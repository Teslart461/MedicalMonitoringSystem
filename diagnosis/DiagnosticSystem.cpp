#include "DiagnosticSystem.h"
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

VitalSigns DiagnosticSystem::analyze(const VitalSigns& data) {
    std::cout << "\n\n--- Запуск системы диагностики ---\n\n";
    VitalSigns current = data;

    for (auto analyzer : analyzers) {
        current = analyzer->process(current);

        bool result = analyzer->check(current);

        // Если это CriticalStateAnalyzer и он вернул true
        if (analyzer->isCritical() && result && notifier) {
            notifier->sendAlert("Пациент в критическом состоянии! Срочно проверьте показатели.");
        }
    }
    std::cout << "----------------------------------\n\n\n";
    return current;
}