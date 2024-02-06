#pragma once

// Konfigurations Struktur eines Benutzers
struct BenutzerKonfiguration
{
	// Anzahl der Etagen, Parklätze für Autos und Motorräder pro Etage mit Standartwerten
	int anzahlEtagen = 2;
	int plaetzeProEtageAuto = 12;
	int plaetzeProEtageMotorrad = 4;
};

// Funktion zum Abrufen der Benutzerkonfiguration
BenutzerKonfiguration holeBenutzerKonfiguration();