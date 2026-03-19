#include "RemoteMonitoringSystem.h"
#include <iostream>

RemoteMonitoringSystem::RemoteMonitoringSystem(
    std::shared_ptr<IReportSystem> reporter,
    std::shared_ptr<IReportSystem> notifier
) : reportGenerator(reporter) {
    // Фасад диагностики создается внутри
    diagnosticSystem = std::make_unique<DiagnosticSystem>(notifier);
}

void RemoteMonitoringSystem::addDevice(std::shared_ptr<IMedicalDevice> device) {
    collector.addDevice(std::move(device));
}

void RemoteMonitoringSystem::addAnalyzer(std::shared_ptr<IDiagnosis> analyzer) {
    diagnosticSystem->addAnalyzer(std::move(analyzer));
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

const ElectronicHealthRecord& RemoteMonitoringSystem::getEHR() const {
    return ehr;
}