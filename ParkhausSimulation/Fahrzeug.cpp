#include "Fahrzeug.h"

// Definition des Konstruktors für die Klasse Fahrzeug
Fahrzeug::Fahrzeug(const std::string& kennzeichen, FahrzeugTyp fahrzeugTyp)
    :
    kennzeichen(kennzeichen),
    fahrzeugTyp(fahrzeugTyp) {}

// Definition der Methode zur Rückgabe des Kennzeichens des Fahrzeugs
const std::string& Fahrzeug::getKennzeichen() const
{
    return kennzeichen;
}

// Definition des Konstruktors für die Klasse Auto
Auto::Auto(const std::string& kennzeichen, FahrzeugTyp fahrzeugTyp)
    :
    Fahrzeug(kennzeichen, fahrzeugTyp) {}

// Definition des Konstruktors für die Klasse Motorrad
Motorrad::Motorrad(const std::string& kennzeichen, FahrzeugTyp fahrzeugTyp)
    :
    Fahrzeug(kennzeichen, fahrzeugTyp) {}

// Definition der Methode zur Rückgabe der aktuellen Position des Fahrzeugs
const Parkplatz& Fahrzeug::getAktuellePosition() const
{
    return aktuellePosition;
}

// Definition der Methode zur Setzung der aktuellen Position des Fahrzeugs
void Fahrzeug::setAktuellePosition(const Parkplatz& position)
{
    aktuellePosition = position;
}

// Definition der Methode zur Rückgabe des Typs des Fahrzeugs
const FahrzeugTyp& Fahrzeug::getFahrzeugTyp() const
{
    return fahrzeugTyp;
}