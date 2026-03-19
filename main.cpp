#include <iostream>
#include <memory>

#include "models/VitalSigns.h"
#include "models/ElectronicHealthRecord.h"

#include "diagnosis/DiagnosticSystem.h"

#include "core/VitalSignsCollector.h"

#include "report/EmergencyNotifier.h"
#include "report/ReportGenerator.h"

#include "diagnosis/CriticalStateAnalyzer.h"
#include "diagnosis/VitalSignsAnalyzer.h"

#include "proxy/BloodPressureMonitorProxy.h"
#include "proxy/HeartRateMonitorProxy.h"
#include "proxy/OximeterProxy.h"

#include <locale>

int main() {
    setlocale(LC_ALL, "RUS");

    // 1. Конфигурирование оборудования (Создаем базовые устройства)
    auto hrm = std::make_shared<HeartRateMonitor>();
    auto bpm = std::make_shared<BloodPressureMonitor>();
    auto oximeter = std::make_shared<Oximeter>();

    // 2. Настраиваем Proxy 
    auto hrmProxy = std::make_shared<HeartRateMonitorProxy>(hrm);
    auto bpmProxy = std::make_shared<BloodPressureMonitorProxy>(bpm);
    auto oximeterProxy = std::make_shared<OximeterProxy>(oximeter);

    // 3. Настраиваем сборщик данных (VitalSignsCollector)
    VitalSignsCollector collector;
    collector.addDevice(hrmProxy);
    collector.addDevice(bpmProxy);
    collector.addDevice(oximeterProxy);

    // 4. Настраиваем систему отчётности и уведомлений
    auto emergencyNotifier = std::make_shared<EmergencyNotifier>();
    auto reportGenerator = std::make_shared<ReportGenerator>();

    // 5. Конфигурируем фасад диагностики
    DiagnosticSystem diagnosticSystem(emergencyNotifier);
    diagnosticSystem.addAnalyzer(std::make_shared<VitalSignsAnalyzer>());
    diagnosticSystem.addAnalyzer(std::make_shared<CriticalStateAnalyzer>());

    // 6. Инициализируем электронную карту
    ElectronicHealthRecord ehr;

    // --- СИМУЛЯЦИЯ РАБОТЫ --- //

    // Итерации сбора данных
    for (int i = 0; i < 2; ++i) {
        VitalSigns currentData = collector.collectData();
        ehr.addRecord(currentData);
        diagnosticSystem.analyze(currentData);
    }

    reportGenerator->generateReport(ehr);

    // 2. Посмотреть только 3-ю по счету запись (индекс 2)
    std::cout << "\nАнализ конкретной итерации:";
    reportGenerator->printSpecificRecord(ehr, 2);

    // 3. Поиск записей с критической сатурацией (фильтрация)
    std::cout << "\nПоиск записей с низкой сатурацией (< 92%):\n";
    for (size_t i = 0; i < ehr.getRecordsCount(); ++i) {
        VitalSigns v = ehr.getRecordByIndex(i);
        if (v.oxygenSaturation < 92) {
            std::cout << "Внимание! В итерации #" << i + 1 << " сатурация была: " << v.oxygenSaturation << "%\n";
        }
    }

    return 0;
}