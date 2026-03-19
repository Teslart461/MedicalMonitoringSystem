#pragma once
#include <vector>
#include "../models/VitalSigns.h"

class IPatientRecord {
public:
    virtual ~IPatientRecord() = default;
    virtual void saveData(const VitalSigns& data) = 0;
    virtual std::vector<VitalSigns> getHistory() const = 0;
};