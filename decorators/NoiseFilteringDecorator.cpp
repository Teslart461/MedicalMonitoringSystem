#include "NoiseFilteringDecorator.h"
#include <iostream>

NoiseFilteringDecorator::NoiseFilteringDecorator(IDiagnosis* diagnosis)
    : DiagnosisDecorator(diagnosis) {
}

VitalSigns NoiseFilteringDecorator::smooth(const VitalSigns& current) {
    if (!hasPrevious) {
        lastData = current;
        hasPrevious = true;
        return current;
    }

    VitalSigns filtered = current;

    filtered.heartRate = (lastData.heartRate + current.heartRate) / 2;
    filtered.systolicPressure =
        (lastData.systolicPressure + current.systolicPressure) / 2;
    filtered.diastolicPressure =
        (lastData.diastolicPressure + current.diastolicPressure) / 2;
    filtered.oxygenSaturation =
        (lastData.oxygenSaturation + current.oxygenSaturation) / 2;

    lastData = filtered;
    return filtered;
}

VitalSigns NoiseFilteringDecorator::process(const VitalSigns& data) {
    std::cout << "[Фильтрация] Сглаживание данных\n";
    return smooth(data);
}

bool NoiseFilteringDecorator::check(const VitalSigns& data) {
    return wrapped->check(data);
}