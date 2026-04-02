#pragma once
#include "DiagnosisDecorator.h"

class TrendAnalysisDecorator : public DiagnosisDecorator {
private:
    VitalSigns previous{};
    bool hasPrevious = false;

public:
    explicit TrendAnalysisDecorator(IDiagnosis* diagnosis);

    bool check(const VitalSigns& data) override;
};