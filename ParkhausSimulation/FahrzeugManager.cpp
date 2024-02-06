#include "FahrzeugManager.h"
#include "Fahrzeug.h"

// Definition der Methode zur Erstellung eines Autos
Fahrzeug* FahrzeugManager::erstelleAuto(const std::string& kennzeichen, FahrzeugTyp fahrzeugTyp)
{
    // Rückgabe eines neuen Auto-Objekts mit den angegebenen Parametern
    return new Auto(kennzeichen, fahrzeugTyp);
}

// Definition der Methode zur Erstellung eines Motorrads
Fahrzeug* FahrzeugManager::erstelleMotorrad(const std::string& kennzeichen, FahrzeugTyp fahrzeugTyp)
{
    // Rückgabe eines neuen Motorrad-Objekts mit den angegebenen Parametern
    return new Motorrad(kennzeichen, fahrzeugTyp);
}