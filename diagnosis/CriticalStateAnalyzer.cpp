#include "CriticalStateAnalyzer.h"
#include <iostream>

bool CriticalStateAnalyzer::check(const VitalSigns& data) {
    std::cout << "[Диагностика] Проверка на критические состояния...\n";
    if (data.oxygenSaturation < 90 || data.systolicPressure > 180 || data.heartRate > 150) {
        return true; // Критическое состояние
    }
    return false;
}