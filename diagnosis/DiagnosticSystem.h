#pragma once
#include "../interfaces/IDiagnosticSystem.h"
#include "../interfaces/IDiagnosis.h"
#include "../interfaces/IReportSystem.h"
#include <vector>

class DiagnosticSystem : public IDiagnosticSystem {
private:
    std::vector<IDiagnosis*> analyzers;
    IReportSystem* notifier;
public:
    DiagnosticSystem(IReportSystem* notif);
    ~DiagnosticSystem();
    void addAnalyzer(IDiagnosis* analyzer);
    VitalSigns analyze(const VitalSigns& data) override;
};