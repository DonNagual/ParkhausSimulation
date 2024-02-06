#pragma once

// Konfigurations Struktur eines Benutzers
struct BenutzerKonfiguration
{
	// Anzahl der Etagen, Parkl�tze f�r Autos und Motorr�der pro Etage mit Standartwerten
	int anzahlEtagen = 2;
	int plaetzeProEtageAuto = 12;
	int plaetzeProEtageMotorrad = 4;
};

// Funktion zum Abrufen der Benutzerkonfiguration
BenutzerKonfiguration holeBenutzerKonfiguration();