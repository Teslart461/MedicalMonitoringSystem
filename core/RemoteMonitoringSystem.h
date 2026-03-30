#pragma once
#include <vector>

#include "../core/VitalSignsCollector.h"

#include "../models/ElectronicHealthRecord.h"
#include "../diagnosis/DiagnosticSystem.h"

class RemoteMonitoringSystem {
private:
    VitalSignsCollector collector;
    ElectronicHealthRecord ehr;
    DiagnosticSystem* diagnosticSystem; 
    IReportSystem* reportGenerator;     
    IReportSystem* notifier;            

public:
    // Конструктор принимает системы отчетности и уведомлений
    RemoteMonitoringSystem(IReportSystem* reporter, IReportSystem* notif);

    // Деструктор: чистим всё, что создали или приняли извне
    ~RemoteMonitoringSystem();

    // Методы конфигурации
    void addDevice(IMedicalDevice* device);
    void addAnalyzer(IDiagnosis* analyzer);

    // Основной рабочий цикл
    void runCycle();

    // Вывод итогов
    void showFinalReport();
};