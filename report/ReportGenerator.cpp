#include "ReportGenerator.h"
#include <iostream>

void ReportGenerator::generateReport(const ElectronicHealthRecord& record) {
    std::cout << "\n=== ПОЛНЫЙ МЕДИЦИНСКИЙ ОТЧЁТ ===\n";
    const auto& history = record.getHistory();

    for (size_t i = 0; i < history.size(); ++i) {
        std::cout << "Запись #" << i + 1 << ": \n"
            << "Пульс: " << history[i].heartRate << " уд/мин\n"
            << "Давление: " << history[i].systolicPressure << "/" << history[i].diastolicPressure << "\n"
            << "Сатурация: " << history[i].oxygenSaturation << "%\n";
    }
    std::cout << "=========================\n";
}

void ReportGenerator::printSpecificRecord(const ElectronicHealthRecord& record, size_t index) {
    if (index >= record.getRecordsCount()) {
        std::cout << "Запись с индексом " << index << " не найдена.\n";
        return;
    }
    VitalSigns data = record.getRecordByIndex(index);
    std::cout << "\n--- Детальный просмотр записи #" << index + 1 << " ---\n"
        << "Пульс: " << data.heartRate << "\n"
        << "Давление: " << data.systolicPressure << "/" << data.diastolicPressure << "\n"
        << "Кислород: " << data.oxygenSaturation << "%\n"
        << "--------------------------------------\n";
}
