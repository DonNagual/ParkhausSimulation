using namespace std;

#include "Parkhaus.h"
#include <iostream>

// Konstruktor von Parkhaus
Parkhaus::Parkhaus(int anzahlEtagen, int plaetzeProEtageAuto, int plaetzeProEtageMotorrad)
    :
    // Initialisiere die Anzahl der Etagen, der Parkpl�tze pro Etage f�r Autos und Motorr�der
    anzahlEtagen(anzahlEtagen),
    plaetzeProEtageAuto(plaetzeProEtageAuto),
    plaetzeProEtageMotorrad(plaetzeProEtageMotorrad)
{
    // Initialisiere die Vektoren f�r Parkpl�tze f�r Autos und Motorr�der mit nullptr
    parkplaetzeAuto.resize(anzahlEtagen, std::vector<Fahrzeug*>(plaetzeProEtageAuto, nullptr));
    parkplaetzeMotorrad.resize(anzahlEtagen, std::vector<Fahrzeug*>(plaetzeProEtageMotorrad, nullptr));
}

int Parkhaus::getAnzahlEtagen() const
{
    return anzahlEtagen;
}

int Parkhaus::getPlaetzeProEtageAuto() const
{
    return plaetzeProEtageAuto;
}

int Parkhaus::getPlaetzeProEtageMotorrad() const
{
    return plaetzeProEtageMotorrad;
}

void Parkhaus::belegeParkplatzAuto(int etage, int platz, Fahrzeug* fahrzeug)
{
    // �berpr�fe die G�ltigkeit der Indizes, bevor auf das Array zugegriffen wird
    if (etage > 0 && etage <= anzahlEtagen && platz > 0 && platz <= plaetzeProEtageAuto)
    {
        if (fahrzeug != nullptr)
        {
            // Setze den Parkplatz f�r das Auto auf die �bergebene Position
            parkplaetzeAuto[etage - 1][platz - 1] = fahrzeug;
        }
        else
        {
            cout << "Fehler: Versuch, einen Parkplatz mit einem nullptr-Fahrzeug zu belegen." << endl;
        }
    }
    else
    {
        // Wenn die �bergebenen Indizes ung�ltig eine Fehlermeldung ausgeben oder anderweitig reagieren
        cout << "Fehler: Ung�ltige Indizes f�r belegeParkplatzAuto." << endl;
    }
}

void Parkhaus::belegeParkplatzMotorrad(int etage, int platz, Fahrzeug* fahrzeug)
{
    // �berpr�fe die G�ltigkeit der Indizes, bevor auf das Array zugegriffen wird
    if (etage > 0 && etage <= anzahlEtagen && platz > 0 && platz <= plaetzeProEtageMotorrad)
    {
        if (fahrzeug != nullptr)
        {
            // Setze den Parkplatz f�r das Motorrad auf die �bergebene Position
            parkplaetzeMotorrad[etage - 1][platz - 1] = fahrzeug;
        }
        else
        {
            cout << "Fehler: Versuch, einen Parkplatz mit einem nullptr-Fahrzeug zu belegen." << endl;
        }
    }
    else
    {
        // Wenn die �bergebenen Indizes ung�ltig eine Fehlermeldung ausgeben oder anderweitig reagieren
        cout << "Fehler: Ung�ltige Indizes f�r belegeParkplatzAuto." << endl;
    }
}

void Parkhaus::gebeParkplatzFrei(int etage, int platz, Fahrzeug* fahrzeug)
{
    // �berpr�fe die G�ltigkeit der Indizes, bevor auf das Array zugegriffen wird
    if (etage > 0 && etage <= anzahlEtagen && platz > 0)
    {
        if (fahrzeug != nullptr)
        {
            // �berpr�fe den Fahrzeugtyp und setze den entsprechenden Parkplatz auf nullptr
            if (fahrzeug->getFahrzeugTyp() == FahrzeugTyp::Auto)
            {
                parkplaetzeAuto[etage - 1][platz - 1] = nullptr;
            }
            else if (fahrzeug->getFahrzeugTyp() == FahrzeugTyp::Motorrad)
            {
                parkplaetzeMotorrad[etage - 1][platz - 1] = nullptr;
            }
            cout << "Der Parkplatz wurde frei gemacht." << endl;
        }
        else
        {
            cout << "Fehler: Nullptr kann nicht gesetzt werden" << endl;
        }
    }
    else
    {
        // Wenn die �bergebenen Indizes ung�ltig sind, eine Fehlermeldung ausgeben oder anderweitig reagieren
        cout << "Fehler: Ung�ltige Indizes f�r gebeParkplatzFrei." << endl;
    }
}

int Parkhaus::getVerfuegbareParkplaetzeAuto() const
{
    int belegtePlaetzeAuto = 0;

    // Z�hle die belegten Parkpl�tze f�r Autos
    for (int etage = 0; etage < anzahlEtagen; ++etage)
    {
        for (int platz = 0; platz < plaetzeProEtageAuto; ++platz)
        {
            if (parkplaetzeAuto[etage][platz] != nullptr)
            {
                ++belegtePlaetzeAuto;
            }
        }
    }
    // Berechne und gib die verf�gbaren Parkpl�tze f�r Autos zur�ck
    return plaetzeProEtageAuto * anzahlEtagen - belegtePlaetzeAuto;
}

int Parkhaus::getVerfuegbareParkplaetzeMotorrad() const
{
    int belegtePlaetzeMotorrad = 0;

    // Z�hle die belegten Parkpl�tze f�r Motorr�der
    for (int etage = 0; etage < anzahlEtagen; ++etage)
    {
        for (int platz = 0; platz < plaetzeProEtageMotorrad; ++platz)
        {
            if (parkplaetzeMotorrad[etage][platz] != nullptr)
            {
                ++belegtePlaetzeMotorrad;
            }
        }
    }
    // Berechne und gib die verf�gbaren Parkpl�tze f�r Motorr�der zur�ck
    return plaetzeProEtageMotorrad * anzahlEtagen - belegtePlaetzeMotorrad;
}

Fahrzeug* Parkhaus::findeFahrzeugNachKennzeichen(const std::string& kennzeichen) const
{
    // Durchsuche alle Etagen und Parkpl�tze nach dem Fahrzeug mit dem angegebenen Kennzeichen
    for (int etage = 0; etage < anzahlEtagen; ++etage)
    {
        // Suche in der Auto-Etage
        for (int platz = 0; platz < plaetzeProEtageAuto; ++platz)
        {
            if (parkplaetzeAuto[etage][platz] != nullptr &&
                parkplaetzeAuto[etage][platz]->getKennzeichen() == kennzeichen)
            {
                return parkplaetzeAuto[etage][platz];
            }
        }

        // Suche in der Motorrad-Etage
        for (int platz = 0; platz < plaetzeProEtageMotorrad; ++platz)
        {
            if (parkplaetzeMotorrad[etage][platz] != nullptr &&
                parkplaetzeMotorrad[etage][platz]->getKennzeichen() == kennzeichen)
            {
                return parkplaetzeMotorrad[etage][platz];
            }
        }
    }

    // Falls das Fahrzeug nicht gefunden wurde, gib nullptr zur�ck
    return nullptr;
}