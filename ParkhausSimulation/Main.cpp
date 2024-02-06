using namespace std;

#include "BenutzerKonfiguration.h"
#include "BenutzerSchnittstelleManager.h"
#include "ParkhausManager.h"
#include <iostream>

int main()
{
	// Benutzerkonfiguration abfragen
	BenutzerKonfiguration konfiguration = holeBenutzerKonfiguration();

	// Initialisierung des Parkhauses über den ParkhausManager
	ParkhausManager parkhausManager;
	Parkhaus parkhaus = parkhausManager.erstelleParkhaus(konfiguration);

	// Initialisierung der Benutzerschnittstelle
	BenutzerSchnittstelleManager benutzerSchnittstelleManager;

	while (true)
	{
		// Anzeigen des Menüs und Holen der Benutzereingabe
		benutzerSchnittstelleManager.neueAnzeige();
		Aktion aktion = benutzerSchnittstelleManager.holeBenutzerEingabe();

		// Ausführen der ausgewählten Aktion
		benutzerSchnittstelleManager.ausfuehrenAktion(aktion, parkhaus);
	}
	return 0;
}