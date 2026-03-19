#pragma once
#include <memory>
#include <vector>

#include "VitalSignsCollector.h"

#include "../models/ElectronicHealthRecord.h"
#include "../diagnosis/DiagnosticSystem.h"

class RemoteMonitoringSystem {
private:
    VitalSignsCollector collector;
    ElectronicHealthRecord ehr;
    std::unique_ptr<DiagnosticSystem> diagnosticSystem;
    std::shared_ptr<IReportSystem> reportGenerator;

public:
    // Конструктор принимает системы отчетности и уведомлений
    RemoteMonitoringSystem(
        std::shared_ptr<IReportSystem> reporter,
        std::shared_ptr<IReportSystem> notifier
    );

    // Методы конфигурации
    void addDevice(std::shared_ptr<IMedicalDevice> device);
    void addAnalyzer(std::shared_ptr<IDiagnosis> analyzer);

    // Основной рабочий цикл
    void runCycle();

    // Вывод итогов
    void showFinalReport();

    // Доступ к медкарте (если нужно для внешних вызовов)
    const ElectronicHealthRecord& getEHR() const;
};