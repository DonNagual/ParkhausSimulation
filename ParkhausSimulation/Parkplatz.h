#pragma once

class Parkplatz
{
private:
    int etage;
    int platz;

public:
    // Standardkonstruktor ohne Parameter
    Parkplatz();

    // Standardkonstruktor mit Parametern f�r Etage und Platz
    Parkplatz(int etage, int platz);

    // Funktion, um die Etage und die Platznummer des Parkplatzes abzurufen
    int getEtage() const;
    int getPlatz() const;

    // Statische Funktion zur Generierung eines zuf�lligen leeren Parkplatzes f�r Autos
    static Parkplatz zufaelligerLeererPlatzAuto(int maxEtagen, int maxPlaetzeProEtage);

    // Statische Funktion zur Generierung eines zuf�lligen leeren Parkplatzes f�r Motorr�der
    static Parkplatz zufaelligerLeererPlatzMotorrad(int maxEtagen, int maxPlaetzeProEtage);
};