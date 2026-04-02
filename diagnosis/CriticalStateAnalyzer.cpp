#include "CriticalStateAnalyzer.h"
#include <iostream>

bool CriticalStateAnalyzer::check(const VitalSigns& data) {
    std::cout << "[Диагностика] Проверка на критические состояния...\n";
    if (data.heartRate < 40 || data.heartRate > 150 || data.systolicPressure < 100 || data.systolicPressure > 180 || data.diastolicPressure < 60 || data.diastolicPressure > 110 || data.oxygenSaturation < 92) {
        return true; // Критическое состояние
    }
    return false;
}

bool CriticalStateAnalyzer::isCritical() const {
    return true;
}
