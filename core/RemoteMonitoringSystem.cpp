#include "RemoteMonitoringSystem.h"
#include <iostream>

RemoteMonitoringSystem::RemoteMonitoringSystem(IReportSystem* reporter, IReportSystem* notif)
    : reportGenerator(reporter), notifier(notif) {
    diagnosticSystem = new DiagnosticSystem(notifier);
}

RemoteMonitoringSystem::~RemoteMonitoringSystem() {
    delete diagnosticSystem;
    delete reportGenerator;
    delete notifier;
}

void RemoteMonitoringSystem::addDevice(IMedicalDevice* device) {
    collector.addDevice(device);
}

void RemoteMonitoringSystem::addAnalyzer(IDiagnosis* analyzer) {
    diagnosticSystem->addAnalyzer(analyzer);
}

void RemoteMonitoringSystem::runCycle() {
    std::cout << "\n[System] Начинаю сеанс сбора и анализа данных..." << std::endl;

    // 1. Собираем данные со всех устройств (через прокси)
    VitalSigns data = collector.collectData();

    // 2. Сохраняем в электронную медицинскую карту
    ehr.addRecord(data);

    // 3. Передаем данные в систему диагностики для анализа
    diagnosticSystem->analyze(data);
}

void RemoteMonitoringSystem::showFinalReport() {
    if (reportGenerator) {
        reportGenerator->generateReport(ehr);
    }
}
