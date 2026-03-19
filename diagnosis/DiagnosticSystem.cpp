#include "DiagnosticSystem.h"
#include "CriticalStateAnalyzer.h"
#include <iostream>

DiagnosticSystem::DiagnosticSystem(std::shared_ptr<IReportSystem> emergencyNotifier)
    : notifier(std::move(emergencyNotifier)) {
}

void DiagnosticSystem::addAnalyzer(std::shared_ptr<IDiagnosis> analyzer) {
    analyzers.push_back(std::move(analyzer));
}

void DiagnosticSystem::analyze(const VitalSigns& data) {
    std::cout << "\n--- Запуск системы диагностики ---\n";
    for (const auto& analyzer : analyzers) {
        bool result = analyzer->check(data);

        // Если это CriticalStateAnalyzer и он вернул true
        auto criticalAnalyzer = std::dynamic_pointer_cast<CriticalStateAnalyzer>(analyzer);
        if (criticalAnalyzer && result && notifier) {
            notifier->sendAlert("Пациент в критическом состоянии! Срочно проверьте показатели.");
        }
    }
    std::cout << "----------------------------------\n";
}