#pragma once

#include <string>
#include "Fahrzeug.h"

// Deklaration der Klasse FahrzeugManager
class FahrzeugManager
{
public:
    // Statische Methode zur Erstellung eines Autos mit gegebenem Kennzeichen und Typ
    static Fahrzeug* erstelleAuto(const std::string& kennzeichen, FahrzeugTyp typ);

    // Statische Methode zur Erstellung eines Motorrads mit gegebenem Kennzeichen und Typ
    static Fahrzeug* erstelleMotorrad(const std::string& kennzeichen, FahrzeugTyp typ);
};