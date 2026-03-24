#pragma once
#include "../models/VitalSigns.h"

class IDiagnosis {
public:
    virtual ~IDiagnosis() = default;
    virtual bool check(const VitalSigns& data) = 0;
    virtual bool isCritical() const;
};