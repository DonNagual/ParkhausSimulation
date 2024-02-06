using namespace std;

#include "BenutzerKonfiguration.h"
#include "BenutzerSchnittstelleManager.h"
#include "ParkhausManager.h"
#include <iostream>

int main()
{
	// Benutzerkonfiguration abfragen
	BenutzerKonfiguration konfiguration = holeBenutzerKonfiguration();

	// Initialisierung des Parkhauses �ber den ParkhausManager
	ParkhausManager parkhausManager;
	Parkhaus parkhaus = parkhausManager.erstelleParkhaus(konfiguration);

	// Initialisierung der Benutzerschnittstelle
	BenutzerSchnittstelleManager benutzerSchnittstelleManager;

	while (true)
	{
		// Anzeigen des Men�s und Holen der Benutzereingabe
		benutzerSchnittstelleManager.neueAnzeige();
		Aktion aktion = benutzerSchnittstelleManager.holeBenutzerEingabe();

		// Ausf�hren der ausgew�hlten Aktion
		benutzerSchnittstelleManager.ausfuehrenAktion(aktion, parkhaus);
	}
	return 0;
}