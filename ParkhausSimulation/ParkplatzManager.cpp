#include "ParkplatzManager.h"
#include "Parkplatz.h"

// Erstelle einen Parkplatz für Autos mit der angegebenen Etage und Platznummer
Parkplatz ParkplatzManager::erstelleParkplatzAuto(int etage, int platz)
{
    return Parkplatz(etage, platz);
}

// Erstelle einen Parkplatz für Motorräder mit der angegebenen Etage und Platznummer
Parkplatz ParkplatzManager::erstelleParkplatzMotorrad(int etage, int platz)
{
    return Parkplatz(etage, platz);
}