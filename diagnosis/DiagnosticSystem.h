#pragma once
#include "../interfaces/IDiagnosticSystem.h"
#include "../interfaces/IDiagnosis.h"
#include "../interfaces/IReportSystem.h"
#include <vector>
#include <memory>

class DiagnosticSystem : public IDiagnosticSystem {
private:
    std::vector<std::shared_ptr<IDiagnosis>> analyzers;
    std::shared_ptr<IReportSystem> notifier;
public:
    DiagnosticSystem(std::shared_ptr<IReportSystem> emergencyNotifier);
    void addAnalyzer(std::shared_ptr<IDiagnosis> analyzer);
    void analyze(const VitalSigns& data) override;
};