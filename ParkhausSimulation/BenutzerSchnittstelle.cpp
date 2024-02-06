using namespace std;

#include "BenutzerSchnittstelle.h"
#include <iostream>
#include "Parkhaus.h"

// Methode zum Abrufen einer Benutzereingabe als Ganzzahl
int BenutzerSchnittstelle::holeEingabeAlsInteger(const string& prompt) const
{
	int eingabe;
	cout << prompt;
	while (!(cin >> eingabe))
	{
		cin.clear();
		cout << "Ungueltige Eingabe.\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Puffer leeren
		cout << "Bitte Aktion auswaehlen: ";
	}
	return eingabe;
}

// Methode zum Abrufen einer Benutzereingabe als Zeichenkette
string BenutzerSchnittstelle::holeEingabeAlsString(const string& prompt) const
{
	string eingabe;
	cout << prompt;
	while (!(cin >> eingabe))
	{
		cin.clear();
		cin.ignore();  // Puffer leeren
	}
	return eingabe;
}

// Methode zum Anzeigen einer Meldung an den Benutzer
void BenutzerSchnittstelle::zeigeMeldung(const string& meldung) const
{
	cout << meldung << endl;
}

// Methode zum Anzeigen einer Fehlermeldung an den Benutzer
void BenutzerSchnittstelle::zeigeFehlermeldung(const string& fehlermeldung) const
{
	cerr << "Fehler:" << fehlermeldung << endl;
}

// Methode zum Abrufen des Fahrzeugtyps vom Benutzer
FahrzeugTyp BenutzerSchnittstelle::holeBenutzerFahrzeugTyp(const std::string& prompt) const
{
	return static_cast<FahrzeugTyp>(holeEingabeAlsInteger(prompt));
}

// Methode zum Konvertieren eines Fahrzeugtyps in eine Zeichenkette
string BenutzerSchnittstelle::fahrzeugTypToString(FahrzeugTyp fahrzeugTyp) const
{
	switch (fahrzeugTyp)
	{
	case FahrzeugTyp::Auto:
		return "Auto";
	case FahrzeugTyp::Motorrad:
		return "Motorrad";
	default:
		return "Unbekannter Typ";
	}
}

// Methode zur Überprüfung, ob eine Bestätigung erforderlich ist
bool BenutzerSchnittstelle::bestaetigungErforderlich() const
{
	// Benutzer um Bestätigung bitten
	std::string bestaetigung = holeEingabeAlsString("Sind Sie sicher? (y / n): ");
	// Bestätigung auswerten und Rückgabe
	return tolower(bestaetigung[0]) == 'y';
}