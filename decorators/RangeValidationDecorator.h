#pragma once
#include "DiagnosisDecorator.h"

class RangeValidationDecorator : public DiagnosisDecorator {
public:
    explicit RangeValidationDecorator(IDiagnosis* diagnosis);

    bool check(const VitalSigns& data) override;
};