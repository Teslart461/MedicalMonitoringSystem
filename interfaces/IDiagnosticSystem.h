#pragma once
#include "../models/VitalSigns.h"

class IDiagnosticSystem {
public:
    virtual ~IDiagnosticSystem() = default;
    virtual VitalSigns analyze(const VitalSigns& data) = 0;
};