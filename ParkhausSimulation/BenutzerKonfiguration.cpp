using namespace std;

#include "BenutzerKonfiguration.h"
#include "BenutzerSchnittstelle.h"
#include <iostream>

// Funktion zum Abrufen der Benutzerkonfiguration
BenutzerKonfiguration holeBenutzerKonfiguration()
{
    // Initialisierung der Konfigurationsstruktur mit Standardwerten
    BenutzerKonfiguration konfiguration{};

    // Objekt f�r die Benutzerschnittstelle erstellen
    BenutzerSchnittstelle benutzerSchnittstelle;

    // Variablen f�r Benutzereingaben und Best�tigung initialisieren
    int auswahl;
    string bestaetigung;
    bool schleifeVerlassen = false;

    // Schleife f�r die Benutzerinteraktion
    while (!schleifeVerlassen)
    {
        // Benutzerschnittstelle anzeigen
        benutzerSchnittstelle.zeigeMeldung
        (
            "*********** Parkhaus Initiakisierung ************\n"
            "-------------------------------------------------\n"
            "**************** Parkhaus Status ****************\n"
            "Etagen: " + to_string(konfiguration.anzahlEtagen) + "\n"
            "Auto Parkpl�tze pro Etage: " + to_string(konfiguration.plaetzeProEtageAuto) + "\n"
            "Motorrad Parkpl�tze pro Etage: " + to_string(konfiguration.plaetzeProEtageMotorrad) + "\n"
            "-------------------------------------------------\n"
            "*********** Parkhaus Initiakisierung ************\n"
            "1. Anzahl Etagen �ndern\n"
            "2. Anzahl Auto Parklatz �ndern\n"
            "3. Anzahl Motorrad Parklatz �ndern\n"
            "4. Parkhaus Initialisieren\n"
            "**********************************************\n"
        );

        // Benutzereingabe abfragen
        auswahl = benutzerSchnittstelle.holeEingabeAlsInteger("Bitte Aktion ausw�hlen: ");
        
        // Benutzereingabe verarbeiten
        switch (auswahl)
        {
            case 1:
            {
                cout << "Anzahl der Etagen eingeben: ";
                cin >> konfiguration.anzahlEtagen;
                break;
            }
            case 2:
            {
                cout << "Anzahl der Parkpl�tze pro Etage f�r Autos eingeben: ";
                cin >> konfiguration.plaetzeProEtageAuto;
                break;
            } 
            case 3:
            {
                cout << "Anzahl der Parkpl�tze pro Etage f�r Motorr�der eingeben: ";
                cin >> konfiguration.plaetzeProEtageMotorrad;
                break;
            } 
            case 4:
            {
                // Benutzerbest�tigung einholen
                bestaetigung = benutzerSchnittstelle.holeEingabeAlsString("Sind Sie sicher, dass Sie das Parkhaus Initialisieren m�chten ? (y / n) : ");

                // Initialisierung des Parkhauses, wenn der Benutzer zustimmt
                if (tolower(bestaetigung[0]) == 'y')
                {
                    benutzerSchnittstelle.zeigeMeldung("Parkhaus wird Initialisiert."); // Wird zwar nicht angezeigt, bleib aber f�r sp�ter drin
                    system("cls");
                    schleifeVerlassen = true; // Schleife beenden
                    break;
                }
                else
                {
                    // Fortsetzen der Parkhausinitialisierung, wenn der Benutzer nicht zustimmt
                    benutzerSchnittstelle.zeigeMeldung("\nParkhaus Initialisierung wird fortgesetzt. Dr�cken sie Enter.");
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }
            } 
            default:
            {
                // Fehlermeldung bei ung�ltiger Eingabe anzeigen
                benutzerSchnittstelle.zeigeFehlermeldung("\nUng�ltigen Men�punkt ausgew�hlt.");
                break;
            }   
        }

        // Warte auf Enter, bevor zum Men� zur�ckgekehrt wird (au�er bei case 4)
        if (!schleifeVerlassen && auswahl > 4)
        {
            cout << "\nDr�cken Sie Enter, um zum Men� zur�ckzukehren...";
            cin.ignore(); // Ignoriere vorherige Enter-Zeichen
            cin.get(); // Warte auf Enter
            system("cls");
        }
        // Bildschirm l�schen f�r die n�chste Benutzereingabe
        system("cls");
    }
    // R�ckgabe der konfigurierten Einstellungen
    return konfiguration;
}