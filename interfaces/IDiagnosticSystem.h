#pragma once
#include "../models/VitalSigns.h"

class IDiagnosticSystem {
public:
    virtual ~IDiagnosticSystem() = default;
    virtual void analyze(const VitalSigns& data) = 0;
};