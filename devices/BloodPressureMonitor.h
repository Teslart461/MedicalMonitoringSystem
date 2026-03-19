#pragma once
#include "../interfaces/IMedicalDevice.h"

class BloodPressureMonitor : public IMedicalDevice {
public:
    VitalSigns getData() override;
};