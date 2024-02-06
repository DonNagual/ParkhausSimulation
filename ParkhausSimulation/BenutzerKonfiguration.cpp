using namespace std;

#include "BenutzerKonfiguration.h"
#include "BenutzerSchnittstelle.h"
#include <iostream>

// Funktion zum Abrufen der Benutzerkonfiguration
BenutzerKonfiguration holeBenutzerKonfiguration()
{
    // Initialisierung der Konfigurationsstruktur mit Standardwerten
    BenutzerKonfiguration konfiguration{};

    // Objekt für die Benutzerschnittstelle erstellen
    BenutzerSchnittstelle benutzerSchnittstelle;

    // Variablen für Benutzereingaben und Bestätigung initialisieren
    int auswahl;
    string bestaetigung;
    bool schleifeVerlassen = false;

    // Schleife für die Benutzerinteraktion
    while (!schleifeVerlassen)
    {
        // Benutzerschnittstelle anzeigen
        benutzerSchnittstelle.zeigeMeldung
        (
            "*********** Parkhaus Initiakisierung ************\n"
            "-------------------------------------------------\n"
            "**************** Parkhaus Status ****************\n"
            "Etagen: " + to_string(konfiguration.anzahlEtagen) + "\n"
            "Auto Parkplätze pro Etage: " + to_string(konfiguration.plaetzeProEtageAuto) + "\n"
            "Motorrad Parkplätze pro Etage: " + to_string(konfiguration.plaetzeProEtageMotorrad) + "\n"
            "-------------------------------------------------\n"
            "*********** Parkhaus Initiakisierung ************\n"
            "1. Anzahl Etagen Ändern\n"
            "2. Anzahl Auto Parklatz Ändern\n"
            "3. Anzahl Motorrad Parklatz Ändern\n"
            "4. Parkhaus Initialisieren\n"
            "**********************************************\n"
        );

        // Benutzereingabe abfragen
        auswahl = benutzerSchnittstelle.holeEingabeAlsInteger("Bitte Aktion auswählen: ");
        
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
                cout << "Anzahl der Parkplätze pro Etage für Autos eingeben: ";
                cin >> konfiguration.plaetzeProEtageAuto;
                break;
            } 
            case 3:
            {
                cout << "Anzahl der Parkplätze pro Etage für Motorräder eingeben: ";
                cin >> konfiguration.plaetzeProEtageMotorrad;
                break;
            } 
            case 4:
            {
                // Benutzerbestätigung einholen
                bestaetigung = benutzerSchnittstelle.holeEingabeAlsString("Sind Sie sicher, dass Sie das Parkhaus Initialisieren möchten ? (y / n) : ");

                // Initialisierung des Parkhauses, wenn der Benutzer zustimmt
                if (tolower(bestaetigung[0]) == 'y')
                {
                    benutzerSchnittstelle.zeigeMeldung("Parkhaus wird Initialisiert."); // Wird zwar nicht angezeigt, bleib aber für später drin
                    system("cls");
                    schleifeVerlassen = true; // Schleife beenden
                    break;
                }
                else
                {
                    // Fortsetzen der Parkhausinitialisierung, wenn der Benutzer nicht zustimmt
                    benutzerSchnittstelle.zeigeMeldung("\nParkhaus Initialisierung wird fortgesetzt. Drücken sie Enter.");
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }
            } 
            default:
            {
                // Fehlermeldung bei ungültiger Eingabe anzeigen
                benutzerSchnittstelle.zeigeFehlermeldung("\nUngültigen Menüpunkt ausgewählt.");
                break;
            }   
        }

        // Warte auf Enter, bevor zum Menü zurückgekehrt wird (außer bei case 4)
        if (!schleifeVerlassen && auswahl > 4)
        {
            cout << "\nDrücken Sie Enter, um zum Menü zurückzukehren...";
            cin.ignore(); // Ignoriere vorherige Enter-Zeichen
            cin.get(); // Warte auf Enter
            system("cls");
        }
        // Bildschirm löschen für die nächste Benutzereingabe
        system("cls");
    }
    // Rückgabe der konfigurierten Einstellungen
    return konfiguration;
}