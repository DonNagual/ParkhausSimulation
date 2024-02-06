#pragma once

#include "Parkplatz.h"

class ParkplatzManager
{
public:
    // Statische Funktion zur Erstellung eines Parkplatzes für Autos mit angegebener Etage und Platznummer
    static Parkplatz erstelleParkplatzAuto(int etage, int platz);

    // Statische Funktion zur Erstellung eines Parkplatzes für Motorräder mit angegebener Etage und Platznummer
    static Parkplatz erstelleParkplatzMotorrad(int etage, int platz);
};