using namespace std;

#include "Parkhaus.h"
#include <iostream>

// Konstruktor von Parkhaus
Parkhaus::Parkhaus(int anzahlEtagen, int plaetzeProEtageAuto, int plaetzeProEtageMotorrad)
    :
    // Initialisiere die Anzahl der Etagen, der Parkplätze pro Etage für Autos und Motorräder
    anzahlEtagen(anzahlEtagen),
    plaetzeProEtageAuto(plaetzeProEtageAuto),
    plaetzeProEtageMotorrad(plaetzeProEtageMotorrad)
{
    // Initialisiere die Vektoren für Parkplätze für Autos und Motorräder mit nullptr
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
    // Überprüfe die Gültigkeit der Indizes, bevor auf das Array zugegriffen wird
    if (etage > 0 && etage <= anzahlEtagen && platz > 0 && platz <= plaetzeProEtageAuto)
    {
        if (fahrzeug != nullptr)
        {
            // Setze den Parkplatz für das Auto auf die übergebene Position
            parkplaetzeAuto[etage - 1][platz - 1] = fahrzeug;
        }
        else
        {
            cout << "Fehler: Versuch, einen Parkplatz mit einem nullptr-Fahrzeug zu belegen." << endl;
        }
    }
    else
    {
        // Wenn die übergebenen Indizes ungültig eine Fehlermeldung ausgeben oder anderweitig reagieren
        cout << "Fehler: Ungültige Indizes für belegeParkplatzAuto." << endl;
    }
}

void Parkhaus::belegeParkplatzMotorrad(int etage, int platz, Fahrzeug* fahrzeug)
{
    // Überprüfe die Gültigkeit der Indizes, bevor auf das Array zugegriffen wird
    if (etage > 0 && etage <= anzahlEtagen && platz > 0 && platz <= plaetzeProEtageMotorrad)
    {
        if (fahrzeug != nullptr)
        {
            // Setze den Parkplatz für das Motorrad auf die übergebene Position
            parkplaetzeMotorrad[etage - 1][platz - 1] = fahrzeug;
        }
        else
        {
            cout << "Fehler: Versuch, einen Parkplatz mit einem nullptr-Fahrzeug zu belegen." << endl;
        }
    }
    else
    {
        // Wenn die übergebenen Indizes ungültig eine Fehlermeldung ausgeben oder anderweitig reagieren
        cout << "Fehler: Ungültige Indizes für belegeParkplatzAuto." << endl;
    }
}

void Parkhaus::gebeParkplatzFrei(int etage, int platz, Fahrzeug* fahrzeug)
{
    // Überprüfe die Gültigkeit der Indizes, bevor auf das Array zugegriffen wird
    if (etage > 0 && etage <= anzahlEtagen && platz > 0)
    {
        if (fahrzeug != nullptr)
        {
            // Überprüfe den Fahrzeugtyp und setze den entsprechenden Parkplatz auf nullptr
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
        // Wenn die übergebenen Indizes ungültig sind, eine Fehlermeldung ausgeben oder anderweitig reagieren
        cout << "Fehler: Ungültige Indizes für gebeParkplatzFrei." << endl;
    }
}

int Parkhaus::getVerfuegbareParkplaetzeAuto() const
{
    int belegtePlaetzeAuto = 0;

    // Zähle die belegten Parkplätze für Autos
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
    // Berechne und gib die verfügbaren Parkplätze für Autos zurück
    return plaetzeProEtageAuto * anzahlEtagen - belegtePlaetzeAuto;
}

int Parkhaus::getVerfuegbareParkplaetzeMotorrad() const
{
    int belegtePlaetzeMotorrad = 0;

    // Zähle die belegten Parkplätze für Motorräder
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
    // Berechne und gib die verfügbaren Parkplätze für Motorräder zurück
    return plaetzeProEtageMotorrad * anzahlEtagen - belegtePlaetzeMotorrad;
}

Fahrzeug* Parkhaus::findeFahrzeugNachKennzeichen(const std::string& kennzeichen) const
{
    // Durchsuche alle Etagen und Parkplätze nach dem Fahrzeug mit dem angegebenen Kennzeichen
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

    // Falls das Fahrzeug nicht gefunden wurde, gib nullptr zurück
    return nullptr;
}