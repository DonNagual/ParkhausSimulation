#pragma once

#include "BenutzerSchnittstelle.h"
#include "Parkhaus.h"

// Aufzählungstyp, der die verschiedenen Aktionen repräsentiert
enum class Aktion
{
    FahrzeugHinzufuegen,
    FahrzeugAusfahren,
    FahrzeugSuchen,
    FreieParkplaetzeAbfragen,
    ParkhausStatusAnzeigen,
    ProgrammBeenden
};

// Statischer Text für das Benutzermenü
static const string MENUE_TEXT =
"********** Parkhaus Simulation **********\n"
"1. Fahrzeug hinzufügen\n"
"2. Fahrzeug ausfahren\n"
"3. Fahrzeug suchen\n"
"4. Parkhausstatus anzeigen\n"
"5. Programm beenden\n"
"*****************************************";

// Klasse für das Benutzermenü-Management
class BenutzerSchnittstelleManager
{
private:
    // Statische Instanz der Benutzerschnittstelle
    static BenutzerSchnittstelle benutzerSchnittstelle;

public:
    // Methode zur Anzeige des Benutzermenüs
    void neueAnzeige() const;

    // Methode zum Abrufen der Benutzereingabe
    Aktion holeBenutzerEingabe() const;

    // Methode zur Ausführung einer Aktion basierend auf der Benutzereingabe
    void ausfuehrenAktion(Aktion aktion, Parkhaus& parkhaus) const;
};