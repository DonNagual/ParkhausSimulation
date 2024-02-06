#pragma once

#include "Parkplatz.h"

class ParkplatzManager
{
public:
    // Statische Funktion zur Erstellung eines Parkplatzes f�r Autos mit angegebener Etage und Platznummer
    static Parkplatz erstelleParkplatzAuto(int etage, int platz);

    // Statische Funktion zur Erstellung eines Parkplatzes f�r Motorr�der mit angegebener Etage und Platznummer
    static Parkplatz erstelleParkplatzMotorrad(int etage, int platz);
};