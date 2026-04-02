#pragma once
#include "DiagnosisDecorator.h"

class NoiseFilteringDecorator : public DiagnosisDecorator {
private:
    VitalSigns lastData;
    bool hasPrevious = false;

    VitalSigns smooth(const VitalSigns& current);

public:
    explicit NoiseFilteringDecorator(IDiagnosis* diagnosis);
    bool check(const VitalSigns& data) override;
    VitalSigns process(const VitalSigns& data);
};