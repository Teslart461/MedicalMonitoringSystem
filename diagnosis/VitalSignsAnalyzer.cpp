#include "VitalSignsAnalyzer.h"
#include <iostream>

bool VitalSignsAnalyzer::check(const VitalSigns& data) {
    std::cout << "[Диагностика] Проверка базовых норм...\n";
    bool abnormal = false;
    if (data.heartRate > 100 || data.heartRate < 60) abnormal = true;
    if (data.systolicPressure > 140 || data.diastolicPressure > 90) abnormal = true;
    if (data.systolicPressure < 100 || data.diastolicPressure < 60) abnormal = true;
    if (data.oxygenSaturation < 96) abnormal = true;

    if (abnormal) std::cout << "  -> Обнаружены легкие отклонения от нормы.\n";
    return abnormal;
}