#include "ParkhausManager.h"
#include "Parkhaus.h"
#include "BenutzerKonfiguration.h"

Parkhaus ParkhausManager::erstelleParkhaus(const BenutzerKonfiguration& konfiguration)
{
    // Erstelle ein Parkhaus-Objekt mit den Parametern aus der �bergebenen Benutzerkonfiguration
    Parkhaus parkhaus(konfiguration.anzahlEtagen, konfiguration.plaetzeProEtageAuto, konfiguration.plaetzeProEtageMotorrad);

    return parkhaus;
}