#pragma once
#include "../interfaces/IDiagnosis.h"

class VitalSignsAnalyzer : public IDiagnosis {
public:
    bool check(const VitalSigns& data) override;
};