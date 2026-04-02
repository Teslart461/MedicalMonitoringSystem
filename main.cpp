#include <iostream>

#include "report/EmergencyNotifier.h"
#include "report/ReportGenerator.h"

#include "diagnosis/CriticalStateAnalyzer.h"
#include "diagnosis/VitalSignsAnalyzer.h"

#include "proxy/BloodPressureMonitorProxy.h"
#include "proxy/HeartRateMonitorProxy.h"
#include "proxy/OximeterProxy.h"

#include "core/RemoteMonitoringSystem.h"

#include "adapters/HeartRateAdapter.h"
#include "adapters/BloodPressureAdapter.h"
#include "adapters/OximeterAdapter.h"

#include "decorators/NoiseFilteringDecorator.h"

#include <locale>

int main() {
    setlocale(LC_ALL, "RUS");

    // 1. Создаем системы вывода
    IReportSystem* reporter = new ReportGenerator();
    IReportSystem* notifier = new EmergencyNotifier();

    // 2. Инициализируем фасад основной системы
    RemoteMonitoringSystem monitoringSystem(reporter, notifier);

    // 3. Конфигурируем оборудование через new
    /*IMedicalDevice* hrDevice = new HeartRateMonitor(20);
    monitoringSystem.addDevice(new HeartRateMonitorProxy(hrDevice));

    IMedicalDevice* bpDevice = new BloodPressureMonitor(15);
    monitoringSystem.addDevice(new BloodPressureMonitorProxy(bpDevice));

    IMedicalDevice* oxDevice = new Oximeter(20);
    monitoringSystem.addDevice(new OximeterProxy(oxDevice));*/

    // Адаптеры
    LegacyHeartRateDevice* legacyHR = new LegacyHeartRateDevice();
    IMedicalDevice* hrAdapter = new HeartRateAdapter(legacyHR);

    monitoringSystem.addDevice(new HeartRateMonitorProxy(hrAdapter));

    LegacyBloodPressureDevice* legacyBP = new LegacyBloodPressureDevice();
    IMedicalDevice* bpAdapter = new BloodPressureAdapter(legacyBP);

    monitoringSystem.addDevice(new BloodPressureMonitorProxy(bpAdapter));

    LegacyOximeter* legacyOx = new LegacyOximeter();
    IMedicalDevice* oxAdapter = new OximeterAdapter(legacyOx);

    monitoringSystem.addDevice(new OximeterProxy(oxAdapter));

    // 4. Настраиваем алгоритмы через new
    //monitoringSystem.addAnalyzer(new VitalSignsAnalyzer());
    //monitoringSystem.addAnalyzer(new CriticalStateAnalyzer());
    IDiagnosis* analyzer =
        new NoiseFilteringDecorator(
                new VitalSignsAnalyzer()
        );

    monitoringSystem.addAnalyzer(analyzer);

    // 5. Запуск работы системы
    std::cout << "=== Система удаленного мониторинга запущена ===" << std::endl;
    for (int i = 0; i < 2; ++i) {
        monitoringSystem.runCycle();
    }

    // 6. Получение финального отчета
    monitoringSystem.showFinalReport();

    return 0;
}