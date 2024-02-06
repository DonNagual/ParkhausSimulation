using namespace std;

#include <vector>
#include <random>  // F�r Zufallszahlengenerator
#include "Parkplatz.h"

// Standardkonstruktor: Initialisiert den Parkplatz mit Etage und Platz auf 0
Parkplatz::Parkplatz() : etage(0), platz(0) {}

// Konstruktor mit Parametern: Initialisiert den Parkplatz mit angegebener Etage und Platz
Parkplatz::Parkplatz(int etage, int platz) : etage(etage), platz(platz) {}

// Funktion, um die Etage des Parkplatzes abzurufen
int Parkplatz::getEtage() const
{
    return etage;
}

// Funktion, um die Platznummer des Parkplatzes abzurufen
int Parkplatz::getPlatz() const
{
    return platz;
}

// Statische Funktion zur Generierung eines zuf�lligen leeren Parkplatzes f�r Autos
Parkplatz Parkplatz::zufaelligerLeererPlatzAuto(int maxEtagen, int maxPlaetzeProEtage)
{
    // Initialisiere den Zufallszahlengenerator mit der aktuellen Zeit
    random_device rd;
    mt19937 generator(rd());

    // Generiere zuf�llige Werte f�r Etage und Platz
    uniform_int_distribution<int> etageDistribution(1, maxEtagen);
    uniform_int_distribution<int> platzDistribution(1, maxPlaetzeProEtage);

    // Zuf�llige Etage und Platznummer erhalten
    int zufaelligeEtage = etageDistribution(generator);
    int zufaelligerPlatz = platzDistribution(generator);

    // Erstelle und gibt den zuf�lligen leeren Platz zur�ck
    return Parkplatz(zufaelligeEtage, zufaelligerPlatz);
}

// Statische Funktion zur Generierung eines zuf�lligen leeren Parkplatzes f�r Motorr�der
Parkplatz Parkplatz::zufaelligerLeererPlatzMotorrad(int maxEtagen, int maxPlaetzeProEtage)
{
    // Initialisiere den Zufallszahlengenerator mit der aktuellen Zeit
    random_device rd;
    mt19937 generator(rd());

    // Generiere zuf�llige Werte f�r Etage und Platz
    uniform_int_distribution<int> etageDistribution(1, maxEtagen);
    uniform_int_distribution<int> platzDistribution(1, maxPlaetzeProEtage);

    // Zuf�llige Etage und Platznummer erhalten
    int zufaelligeEtage = etageDistribution(generator);
    int zufaelligerPlatz = platzDistribution(generator);

    // Erstelle und gibt den zuf�lligen leeren Platz zur�ck
    return Parkplatz(zufaelligeEtage, zufaelligerPlatz);
}