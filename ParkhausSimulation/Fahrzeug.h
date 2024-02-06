#pragma once

#include <string>
#include "Parkplatz.h"
#include "BenutzerSchnittstelle.h"

// Deklaration der Klasse Fahrzeug
class Fahrzeug
{
private:
    // Kennzeichen, Aktuelle Position und Typ des Fahrzeugs
    std::string kennzeichen;
    Parkplatz aktuellePosition;
    FahrzeugTyp fahrzeugTyp;

public:
    // Konstruktor für die Initialisierung eines Fahrzeugs
    Fahrzeug(const std::string& kennzeichen, FahrzeugTyp fahrzeugTyp);

    // Methoden zur Rückgabe des Kennzeichens, Aktuelle Position und Typdes des Fahrzeugs
    const std::string& getKennzeichen() const;
    const Parkplatz& getAktuellePosition() const;
    const FahrzeugTyp& getFahrzeugTyp() const;

    // Methode zur Setzung der aktuellen Position des Fahrzeugs
    void setAktuellePosition(const Parkplatz& position);
};

// Deklaration der Klasse Auto, die von der Klasse Fahrzeug erbt
class Auto : public Fahrzeug
{
public:
    // Konstruktor für die Initialisierung eines Autos
    Auto(const std::string& kennzeichen, FahrzeugTyp fahrzeugTyp);
};

// Deklaration der Klasse Motorrad, die von der Klasse Fahrzeug erbt
class Motorrad : public Fahrzeug
{
public:
    // Konstruktor für die Initialisierung eines Motorrads
    Motorrad(const std::string& kennzeichen, FahrzeugTyp fahrzeugTyp);
};