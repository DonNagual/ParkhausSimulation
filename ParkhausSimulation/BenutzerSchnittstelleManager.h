#pragma once

#include "BenutzerSchnittstelle.h"
#include "Parkhaus.h"

// Aufz�hlungstyp, der die verschiedenen Aktionen repr�sentiert
enum class Aktion
{
    FahrzeugHinzufuegen,
    FahrzeugAusfahren,
    FahrzeugSuchen,
    FreieParkplaetzeAbfragen,
    ParkhausStatusAnzeigen,
    ProgrammBeenden
};

// Statischer Text f�r das Benutzermen�
static const string MENUE_TEXT =
"********** Parkhaus Simulation **********\n"
"1. Fahrzeug hinzuf�gen\n"
"2. Fahrzeug ausfahren\n"
"3. Fahrzeug suchen\n"
"4. Parkhausstatus anzeigen\n"
"5. Programm beenden\n"
"*****************************************";

// Klasse f�r das Benutzermen�-Management
class BenutzerSchnittstelleManager
{
private:
    // Statische Instanz der Benutzerschnittstelle
    static BenutzerSchnittstelle benutzerSchnittstelle;

public:
    // Methode zur Anzeige des Benutzermen�s
    void neueAnzeige() const;

    // Methode zum Abrufen der Benutzereingabe
    Aktion holeBenutzerEingabe() const;

    // Methode zur Ausf�hrung einer Aktion basierend auf der Benutzereingabe
    void ausfuehrenAktion(Aktion aktion, Parkhaus& parkhaus) const;
};