#pragma once
#include "../interfaces/IDiagnosis.h"

class CriticalStateAnalyzer : public IDiagnosis {
public:
    bool check(const VitalSigns& data) override;
};