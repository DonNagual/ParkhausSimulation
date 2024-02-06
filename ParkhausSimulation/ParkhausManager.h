#pragma once

#include "Parkhaus.h"
#include "FahrzeugManager.h"
#include "BenutzerKonfiguration.h"

class ParkhausManager
{
public:
    // Methode zum Erstellen eines Parkhauses basierend auf Benutzerkonfiguration
    Parkhaus erstelleParkhaus(const BenutzerKonfiguration& konfiguration);
};