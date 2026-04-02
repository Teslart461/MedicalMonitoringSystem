#include "TrendAnalysisDecorator.h"
#include <iostream>

TrendAnalysisDecorator::TrendAnalysisDecorator(IDiagnosis* diagnosis)
    : DiagnosisDecorator(diagnosis) {
}

bool TrendAnalysisDecorator::check(const VitalSigns& data) {
    std::cout << "[Тренд] Анализ динамики показателей...\n";

    if (hasPrevious) {
        int deltaHR = data.heartRate - previous.heartRate;
        int deltaSpO2 = previous.oxygenSaturation - data.oxygenSaturation;

        if (deltaHR > 30) {
            std::cout << "  -> Резкий рост ЧСС (" << deltaHR << ")\n";
        }

        if (deltaSpO2 > 5) {
            std::cout << "  -> Падение сатурации (" << deltaSpO2 << "%)\n";
        }
    }

    previous = data;
    hasPrevious = true;

    return wrapped->check(data);
}