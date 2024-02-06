#pragma once

#include <string>

// Aufzählungstyp, der die verschiedenen Fahrzeugtypen repräsentiert
enum class FahrzeugTyp
{
	Auto = 1,
	Motorrad = 2
};

// Klasse für die Benutzerschnittstelle
class BenutzerSchnittstelle
{
public:
	// Methode zum Abrufen einer Benutzereingabe als Ganzzahl
	int holeEingabeAlsInteger(const std::string& prompt) const;

	// Methode zum Abrufen einer Benutzereingabe als Zeichenkette
	std::string holeEingabeAlsString(const std::string& prompt) const;

	// Methode zum Anzeigen einer Meldung an den Benutzer
	void zeigeMeldung(const std::string& meldung) const;

	// Methode zum Anzeigen einer Fehlermeldung an den Benutzer
	void zeigeFehlermeldung(const std::string& fehlermeldung) const;

	// Methode zum Abrufen des Fahrzeugtyps vom Benutzer
	FahrzeugTyp holeBenutzerFahrzeugTyp(const std::string& prompt) const;

	// Methode zum Konvertieren eines Fahrzeugtyps in eine Zeichenkette
	std::string fahrzeugTypToString(FahrzeugTyp fahrzeugTyp) const;

	// Methode zur Überprüfung, ob eine Bestätigung erforderlich ist
	bool bestaetigungErforderlich() const;
};