#pragma once
#include "../interfaces/IMedicalDevice.h"

class HeartRateMonitor : public IMedicalDevice {
private:
    int batteryLevel;
public:
    HeartRateMonitor(int initialBattery);
    VitalSigns getData() override;
    int getBatteryLevel() const override;
};