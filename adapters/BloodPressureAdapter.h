#pragma once
#include "../interfaces/IMedicalDevice.h"
#include "LegacyBloodPressureDevice.h"
#include "../models/VitalSigns.h"

class BloodPressureAdapter : public IMedicalDevice {
private:
    LegacyBloodPressureDevice* device;

public:
    BloodPressureAdapter(LegacyBloodPressureDevice* dev);
    ~BloodPressureAdapter();
    VitalSigns getData() override;
    int getBatteryLevel() const;
};