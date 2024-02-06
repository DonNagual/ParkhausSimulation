using namespace std;

#include <iostream>
#include <cctype>
#include "BenutzerSchnittstelleManager.h"
#include "Parkhaus.h"
#include "Parkplatz.h"
#include "FahrzeugManager.h"

// Statische Instanz der Benutzerschnittstelle initialisieren
BenutzerSchnittstelle BenutzerSchnittstelleManager::benutzerSchnittstelle;

// Methode zur Anzeige des Benutzermen�s
void BenutzerSchnittstelleManager::neueAnzeige() const
{
	cout << MENUE_TEXT << endl;
}

// Methode zum Abrufen der Benutzereingabe
Aktion BenutzerSchnittstelleManager::holeBenutzerEingabe() const
{
	// Benutzer zur Auswahl einer Aktion auffordern
	int eingabe = benutzerSchnittstelle.holeEingabeAlsInteger("Bitte Aktion ausw�hlen: ");

	// Aktion basierend auf der Benutzereingabe ausw�hlen
	switch (eingabe)
	{
	case 1:
		return Aktion::FahrzeugHinzufuegen;
	case 2:
		return Aktion::FahrzeugAusfahren;
	case 3:
		return Aktion::FahrzeugSuchen;
	case 4:
		return Aktion::ParkhausStatusAnzeigen;
	case 5:
		return Aktion::ProgrammBeenden;
	default:
		// Ung�ltige Eingabe, Fehlermeldung anzeigen
		benutzerSchnittstelle.zeigeFehlermeldung("\nUng�ltigen Men�punkt ausgew�hlt.");
		break;
	}
}

// Methode zur Ausf�hrung einer Aktion basierend auf der Benutzereingabe
void BenutzerSchnittstelleManager::ausfuehrenAktion(Aktion aktion, Parkhaus& parkhaus) const
{
	switch (aktion)
	{
		// Hinzuf�gen eines Fahrzeugs
		case Aktion::FahrzeugHinzufuegen:
		{
			// Kennzeichen des Fahrzeugs abfragen
			string kennzeichen = benutzerSchnittstelle.holeEingabeAlsString("Bitte geben Sie das Kennzeichen des Fahrzeugs ein: ");

			// Fahrzeugtyp abfragen (Auto oder Motorrad)
			FahrzeugTyp fahrzeugTyp = benutzerSchnittstelle.holeBenutzerFahrzeugTyp("Handelt es sich um ein Auto(1) oder Motorrad(2): ");

			// Best�tigung f�r das Hinzuf�gen des Fahrzeugs abfragen
			if (benutzerSchnittstelle.bestaetigungErforderlich())
			{
				// �berpr�fe, ob es noch freie Parkpl�tze f�r Autos bzw. Motorr�der gibt
				if (fahrzeugTyp == FahrzeugTyp::Auto && parkhaus.getVerfuegbareParkplaetzeAuto() == 0)
				{
					benutzerSchnittstelle.zeigeMeldung("Es sind keine freien Parkpl�tze f�r Autos mehr verf�gbar.");
					break;
				}
				else if (fahrzeugTyp == FahrzeugTyp::Motorrad && parkhaus.getVerfuegbareParkplaetzeMotorrad() == 0)
				{
					benutzerSchnittstelle.zeigeMeldung("Es sind keine freien Parkpl�tze f�r Motorr�der mehr verf�gbar.");
					break;
				}

				// Zuf�lligen leeren Parkplatz f�r das Auto oder Motorrad bestimmen
				Parkplatz zufaelligerParkplatz;
				if (fahrzeugTyp == FahrzeugTyp::Auto)
				{
					zufaelligerParkplatz = Parkplatz::zufaelligerLeererPlatzAuto(parkhaus.getAnzahlEtagen(), parkhaus.getPlaetzeProEtageAuto());
				}
				else if (fahrzeugTyp == FahrzeugTyp::Motorrad)
				{
					zufaelligerParkplatz = Parkplatz::zufaelligerLeererPlatzMotorrad(parkhaus.getAnzahlEtagen(), parkhaus.getPlaetzeProEtageMotorrad());
				}

				// Neues Fahrzeug erstellen und auf den zuf�lligen Parkplatz setzen
				Fahrzeug* neuesFahrzeug = (fahrzeugTyp == FahrzeugTyp::Auto) ? FahrzeugManager::erstelleAuto(kennzeichen, fahrzeugTyp) : FahrzeugManager::erstelleMotorrad(kennzeichen, fahrzeugTyp);
				neuesFahrzeug->setAktuellePosition(zufaelligerParkplatz);

				// Das Fahrzeug dem Parkplatz (Auto oder Motorrad) hinzuf�gen
				if (fahrzeugTyp == FahrzeugTyp::Auto)
				{
					parkhaus.belegeParkplatzAuto(zufaelligerParkplatz.getEtage(), zufaelligerParkplatz.getPlatz(), neuesFahrzeug);
				}
				else if (fahrzeugTyp == FahrzeugTyp::Motorrad)
				{
					parkhaus.belegeParkplatzMotorrad(zufaelligerParkplatz.getEtage(), zufaelligerParkplatz.getPlatz(), neuesFahrzeug);
				}

				// Meldung �ber das Hinzuf�gen des Fahrzeugs anzeigen
				const Parkplatz& aktuellePosition = neuesFahrzeug->getAktuellePosition();
				const FahrzeugTyp& fahrzeugTypDesNeuenFahrzeugs = neuesFahrzeug->getFahrzeugTyp();
				benutzerSchnittstelle.zeigeMeldung
				(
					"Das " + benutzerSchnittstelle.fahrzeugTypToString(fahrzeugTypDesNeuenFahrzeugs) +
					" mit dem Kennezeichen " + kennzeichen +
					" parkt auf Etage " + to_string(aktuellePosition.getEtage()) +
					" Platz " + to_string(aktuellePosition.getPlatz())
				);
			}
			else
			{
				// Meldung anzeigen, dass das Fahrzeug nicht eingefahren ist
				benutzerSchnittstelle.zeigeMeldung("Das Fahrzeug ist in das Parkhaus nicht eingefahren.");
			}
			break;
		}
		// Ausfahren eines Fahrzeugs
		case Aktion::FahrzeugAusfahren:
		{
			// Kennzeichen des auszufahrenden Fahrzeugs abfragen
			string kennzeichenAusfahrt = benutzerSchnittstelle.holeEingabeAlsString("Bitte geben Sie das Kennzeichen des auszufahrenden Fahrzeugs ein: ");

			// Suche nach dem Fahrzeug mit dem angegebenen Kennzeichen
			Fahrzeug* ausfahrendesFahrzeug = parkhaus.findeFahrzeugNachKennzeichen(kennzeichenAusfahrt);

			if (ausfahrendesFahrzeug != nullptr)
			{
				// Best�tigung f�r das Ausfahren des Fahrzeugs abfragen
				if (benutzerSchnittstelle.bestaetigungErforderlich())
				{
					// Das Fahrzeug wurde gefunden, �berpr�fe, ob es sich um ein Auto oder Motorrad handelt
					const FahrzeugTyp& fahrzeugTyp = ausfahrendesFahrzeug->getFahrzeugTyp();

					// Meldung �ber das Ausfahren des Fahrzeugs anzeigen
					const Parkplatz& position = ausfahrendesFahrzeug->getAktuellePosition();
					benutzerSchnittstelle.zeigeMeldung("Das " + benutzerSchnittstelle.fahrzeugTypToString(fahrzeugTyp) +
						" mit dem " + kennzeichenAusfahrt +
						" hat den Parkplatz auf Etage " + to_string(position.getEtage()) +
						", Platz " + to_string(position.getPlatz()) +
						" verlassen.");

					// Parkplatz freigeben und Speicher freigeben
					parkhaus.gebeParkplatzFrei(position.getEtage(), position.getPlatz(), ausfahrendesFahrzeug);
					delete ausfahrendesFahrzeug;
				}			
				else
				{
					// Meldung anzeigen, dass das Ausfahren des Fahrzeugs abgebrochen wurde
					benutzerSchnittstelle.zeigeMeldung("Ausfahren des Fahrzeugs abgebrochen.");
				}
			}
			else
			{
				// Meldung anzeigen, dass das Fahrzeug nicht gefunden wurde
				benutzerSchnittstelle.zeigeMeldung("Das Fahrzeug mit dem Kennzeichen " + kennzeichenAusfahrt + " wurde nicht gefunden.");
			}
			break;
		}
		// Suchen eines Fahrzeugs 
		case Aktion::FahrzeugSuchen:
		{
			// Eingabe des Kennzeichens des zu suchenden Fahrzeugs durch den Benutzer
			string kennzeichenSuche = benutzerSchnittstelle.holeEingabeAlsString("Bitte geben Sie das Kennzeichen des zu suchenden Fahrzeugs ein: ");

			// Suche nach dem Fahrzeug mit dem angegebenen Kennzeichen im Parkhaus
			Fahrzeug* gefundenesFahrzeug = parkhaus.findeFahrzeugNachKennzeichen(kennzeichenSuche);

			// �berpr�fen, ob das Fahrzeug gefunden wurde
			if (gefundenesFahrzeug != nullptr)
			{
				// Das Fahrzeug wurde gefunden
				const Parkplatz& gefundenePosition = gefundenesFahrzeug->getAktuellePosition();
				const FahrzeugTyp& fahrzeugTypDesNeuenFahrzeugs = gefundenesFahrzeug->getFahrzeugTyp();

				// Anzeigen der Meldung, dass das Fahrzeug gefunden wurde, mit Details zur Position und Fahrzeugtyp
				benutzerSchnittstelle.zeigeMeldung
				(
					"Das Fahrzeug mit Kennzeichen " + kennzeichenSuche + " wurde gefunden.\n"
					"Es steht auf Etage " + to_string(gefundenePosition.getEtage()) + ", Platz " + to_string(gefundenePosition.getPlatz()) + "\n"
					"Der Fahrzeugtyp ist ein " + benutzerSchnittstelle.fahrzeugTypToString(fahrzeugTypDesNeuenFahrzeugs)
				);
			}
			else
			{
				// Das Fahrzeug wurde nicht gefunden
				cout << "Das Fahrzeug mit Kennzeichen " << kennzeichenSuche << " wurde nicht gefunden." << endl;
			}
			break;
		}
		// Anzeige des Parkhausstatus
		case Aktion::ParkhausStatusAnzeigen:
		{
			// Bildschirm l�schen
			system("cls");

			// Parkhausstatus anzeigen
			benutzerSchnittstelle.zeigeMeldung
			(
				"**************** Parkhaus Status ****************\n" 
				"Anzahl Etagen: " + to_string(parkhaus.getAnzahlEtagen()) + "\n" +
				"Anzahl Parkpl�tze pro Etage f�r Autos: " + to_string(parkhaus.getPlaetzeProEtageAuto()) + "\n" +
				"Anzahl Parkpl�tze pro Etage f�r Motorr�der: " + to_string(parkhaus.getPlaetzeProEtageMotorrad()) + "\n" +
				"-------------------------------------------------\n"
				"Anzahl verf�gbarer Parkpl�tze f�r Autos: " + to_string(parkhaus.getVerfuegbareParkplaetzeAuto()) + "\n" +
				"Anzahl verf�gbarer Parkpl�tze f�r Motorr�der: " + to_string(parkhaus.getVerfuegbareParkplaetzeMotorrad()) + "\n" +
				"*************************************************"
			);
			break;
		}
		// Beenden des Programms
		case Aktion::ProgrammBeenden:
		{
			// Best�tigung f�r das Beenden des Programms abfragen
			string bestaetigung = benutzerSchnittstelle.holeEingabeAlsString("Sind Sie sicher, dass Sie das Programm beenden m�chten ? (y / n) : ");

			// �berpr�fen, ob die Best�tigung positiv ist
			if (tolower(bestaetigung[0]) == 'y')
			{
				// Meldung anzeigen, dass das Programm beendet wurde, und das Programm beenden
				benutzerSchnittstelle.zeigeMeldung("\nProgramm wurde beendet.");
				exit(0);
			}
			else
			{
				// Meldung anzeigen, dass die Parkhaus-Simulation fortgesetzt wird und auf Benutzereingabe warten
				benutzerSchnittstelle.zeigeMeldung("\nParkhaus Simulation wird fortgesetzt. Dr�cken sie Enter.");
				cin.ignore();
				cin.get();
				system("cls");
			}
			break;
		}
	}

	// Warte auf Enter, bevor zum Men� zur�ckgekehrt wird (au�er bei Aktion ProgrammBeenden)
	if (aktion != Aktion::ProgrammBeenden)
	{
		cout << "\nDr�cken Sie Enter, um zum Men� zur�ckzukehren...";
		cin.ignore(); // Ignoriere vorherige Enter-Zeichen
		cin.get(); // Warte auf Enter
		system("cls");
	}
}