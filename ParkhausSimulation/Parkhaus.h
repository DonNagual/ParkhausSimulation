#pragma once

#include <vector>
#include "Fahrzeug.h"
#include "Parkplatz.h"

class Parkhaus
{
private:
    // Anzahl der Etagen und Parkplätze pro Etage für Autos und Motorräder im Parkhaus
    int anzahlEtagen;
    int plaetzeProEtageAuto;
    int plaetzeProEtageMotorrad;

    // Vektoren zur Speicherung der Parkplätze für Autos und Motorräder
    std::vector<std::vector<Fahrzeug*>> parkplaetzeAuto;
    std::vector<std::vector<Fahrzeug*>> parkplaetzeMotorrad;

public:
    // Konstruktor
    Parkhaus(int anzahlEtagen, int plaetzeProEtageAuto, int plaetzeProEtageMotorrad);

    // Methoden zur Rückgabe der Anzahl der Etagen und der Parkplätze pro Etage für Autos und Motorräder
    int getAnzahlEtagen() const;
    int getPlaetzeProEtageAuto() const;
    int getPlaetzeProEtageMotorrad() const;

    // Methoden zur Belegung eines Parkplatzes für Autos und Motorräder
    void belegeParkplatzAuto(int etage, int platz, Fahrzeug* fahrzeug);
    void belegeParkplatzMotorrad(int etage, int platz, Fahrzeug* fahrzeug);

    // Methode zum Freigeben eines Parkplatzes
    void gebeParkplatzFrei(int etage, int platz, Fahrzeug* fahrzeug);

    // Methoden zur Rückgabe der verfügbaren Parkplätze für Autos und Motorräder
    int getVerfuegbareParkplaetzeAuto() const;
    int getVerfuegbareParkplaetzeMotorrad() const;

    // Methode zum Finden eines Fahrzeugs anhand des Kennzeichens
    Fahrzeug* findeFahrzeugNachKennzeichen(const std::string& kennzeichen) const;
};