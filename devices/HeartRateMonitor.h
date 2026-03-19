#pragma once
#include "../interfaces/IMedicalDevice.h"

class HeartRateMonitor : public IMedicalDevice {
public:
    VitalSigns getData() override;
};