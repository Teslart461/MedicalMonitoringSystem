#pragma once

#include "../interfaces/IMedicalDevice.h"
#include "LegacyHeartRateDevice.h"
#include "../models/VitalSigns.h"

class HeartRateAdapter : public IMedicalDevice {
private:
    LegacyHeartRateDevice* device;

public:
    HeartRateAdapter(LegacyHeartRateDevice* dev);
    ~HeartRateAdapter();
    VitalSigns getData() override;
    int getBatteryLevel() const;
};