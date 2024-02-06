#pragma once

class Parkplatz
{
private:
    int etage;
    int platz;

public:
    // Standardkonstruktor ohne Parameter
    Parkplatz();

    // Standardkonstruktor mit Parametern für Etage und Platz
    Parkplatz(int etage, int platz);

    // Funktion, um die Etage und die Platznummer des Parkplatzes abzurufen
    int getEtage() const;
    int getPlatz() const;

    // Statische Funktion zur Generierung eines zufälligen leeren Parkplatzes für Autos
    static Parkplatz zufaelligerLeererPlatzAuto(int maxEtagen, int maxPlaetzeProEtage);

    // Statische Funktion zur Generierung eines zufälligen leeren Parkplatzes für Motorräder
    static Parkplatz zufaelligerLeererPlatzMotorrad(int maxEtagen, int maxPlaetzeProEtage);
};