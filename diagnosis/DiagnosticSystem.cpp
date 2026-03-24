#include "DiagnosticSystem.h"
#include "CriticalStateAnalyzer.h"
#include <iostream>

DiagnosticSystem::DiagnosticSystem(IReportSystem* notif) : notifier(notif) {

}

DiagnosticSystem::~DiagnosticSystem() {
    for (auto analyzer : analyzers) {
        delete analyzer; // Очищаем анализаторы
    }
}

void DiagnosticSystem::addAnalyzer(IDiagnosis* analyzer) {
    analyzers.push_back(analyzer);
}

void DiagnosticSystem::analyze(const VitalSigns& data) {
    std::cout << "\n\n--- Запуск системы диагностики ---\n\n";
    for (const auto& analyzer : analyzers) {
        bool result = analyzer->check(data);

        // Если это CriticalStateAnalyzer и он вернул true
        if (analyzer->isCritical() && result && notifier) {
            notifier->sendAlert("Пациент в критическом состоянии! Срочно проверьте показатели.");
        }
    }
    std::cout << "----------------------------------\n\n\n";
}