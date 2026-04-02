#include "RangeValidationDecorator.h"
#include <iostream>

RangeValidationDecorator::RangeValidationDecorator(IDiagnosis* diagnosis)
    : DiagnosisDecorator(diagnosis) {
}

bool RangeValidationDecorator::check(const VitalSigns& data) {
    std::cout << "[Валидация] Проверка диапазонов значений...\n";

    bool valid = true;

    if (data.heartRate < 20 || data.heartRate > 170) {
        std::cout << "Некорректная ЧСС!\n";
        valid = false;
    }

    if (data.systolicPressure < 50 || data.systolicPressure > 230) {
        std::cout << "Некорректное систолическое давление!\n";
        valid = false;
    }

    if (data.diastolicPressure < 30 || data.diastolicPressure > 150) {
        std::cout << "Некорректное диастолическое давление!\n";
        valid = false;
    }

    if (data.oxygenSaturation < 70 || data.oxygenSaturation > 100) {
        std::cout << "Некорректная сатурация!\n";
        valid = false;
    }

    // Если хотя бы один параметр некорректен — дальше не идём
    if (!valid) {
        return false;
    }

    // Все параметры корректны — делегируем дальше по цепочке
    return wrapped->check(data);
}