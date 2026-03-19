#include <iostream>
#include <memory>

#include "report/EmergencyNotifier.h"
#include "report/ReportGenerator.h"

#include "diagnosis/CriticalStateAnalyzer.h"
#include "diagnosis/VitalSignsAnalyzer.h"

#include "proxy/BloodPressureMonitorProxy.h"
#include "proxy/HeartRateMonitorProxy.h"
#include "proxy/OximeterProxy.h"

#include "core/RemoteMonitoringSystem.h"

#include <locale>

int main() {
    setlocale(LC_ALL, "RUS");

    // 1. Создаем систему и зависимости
    auto reporter = std::make_shared<ReportGenerator>();
    auto notifier = std::make_shared<EmergencyNotifier>();

    // 2. Инициализация основной системы
    RemoteMonitoringSystem monitoringSystem(reporter, notifier);

    // 3. Конфигурирование оборудования (Датчики + Прокси)
    // Оборачиваем реальные датчики в прокси-объекты
    auto haertRateDevice = std::make_shared<HeartRateMonitor>();
    monitoringSystem.addDevice(std::make_shared<HeartRateMonitorProxy>(haertRateDevice));

    auto bloodPressureDevice = std::make_shared<BloodPressureMonitor>();
    monitoringSystem.addDevice(std::make_shared<BloodPressureMonitorProxy>(bloodPressureDevice));

    auto oximeterDevice = std::make_shared<Oximeter>();
    monitoringSystem.addDevice(std::make_shared<OximeterProxy>(oximeterDevice));

    // 4. Настройка алгоритмов диагностики
    monitoringSystem.addAnalyzer(std::make_shared<VitalSignsAnalyzer>());
    monitoringSystem.addAnalyzer(std::make_shared<CriticalStateAnalyzer>());

    // 5. Запуск работы системы
    std::cout << "=== Система удаленного мониторинга запущена ===" << std::endl;
    for (int i = 0; i < 3; ++i) {
        monitoringSystem.runCycle();
    }

    // 6. Получение финального отчета
    monitoringSystem.showFinalReport();

    return 0;
}