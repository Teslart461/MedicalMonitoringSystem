#pragma once
#include "../interfaces/IDiagnosis.h"

class DiagnosisDecorator : public IDiagnosis {
protected:
    IDiagnosis* wrapped;   // Декорируемый объект

public:
    explicit DiagnosisDecorator(IDiagnosis* diagnosis);
    virtual ~DiagnosisDecorator();

    bool check(const VitalSigns& data) override;
    VitalSigns process(const VitalSigns& data);
};