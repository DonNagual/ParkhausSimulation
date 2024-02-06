#pragma once

#include <vector>
#include "Fahrzeug.h"
#include "Parkplatz.h"

class Parkhaus
{
private:
    // Anzahl der Etagen und Parkpl�tze pro Etage f�r Autos und Motorr�der im Parkhaus
    int anzahlEtagen;
    int plaetzeProEtageAuto;
    int plaetzeProEtageMotorrad;

    // Vektoren zur Speicherung der Parkpl�tze f�r Autos und Motorr�der
    std::vector<std::vector<Fahrzeug*>> parkplaetzeAuto;
    std::vector<std::vector<Fahrzeug*>> parkplaetzeMotorrad;

public:
    // Konstruktor
    Parkhaus(int anzahlEtagen, int plaetzeProEtageAuto, int plaetzeProEtageMotorrad);

    // Methoden zur R�ckgabe der Anzahl der Etagen und der Parkpl�tze pro Etage f�r Autos und Motorr�der
    int getAnzahlEtagen() const;
    int getPlaetzeProEtageAuto() const;
    int getPlaetzeProEtageMotorrad() const;

    // Methoden zur Belegung eines Parkplatzes f�r Autos und Motorr�der
    void belegeParkplatzAuto(int etage, int platz, Fahrzeug* fahrzeug);
    void belegeParkplatzMotorrad(int etage, int platz, Fahrzeug* fahrzeug);

    // Methode zum Freigeben eines Parkplatzes
    void gebeParkplatzFrei(int etage, int platz, Fahrzeug* fahrzeug);

    // Methoden zur R�ckgabe der verf�gbaren Parkpl�tze f�r Autos und Motorr�der
    int getVerfuegbareParkplaetzeAuto() const;
    int getVerfuegbareParkplaetzeMotorrad() const;

    // Methode zum Finden eines Fahrzeugs anhand des Kennzeichens
    Fahrzeug* findeFahrzeugNachKennzeichen(const std::string& kennzeichen) const;
};