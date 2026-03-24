#pragma once
#include "../interfaces/IDiagnosticSystem.h"
#include "../interfaces/IDiagnosis.h"
#include "../interfaces/IReportSystem.h"
#include <vector>
#include <memory>

class DiagnosticSystem : public IDiagnosticSystem {
private:
    std::vector<IDiagnosis*> analyzers;
    IReportSystem* notifier;
public:
    DiagnosticSystem(IReportSystem* notif);
    ~DiagnosticSystem();
    void addAnalyzer(IDiagnosis* analyzer);
    void analyze(const VitalSigns& data) override;
};