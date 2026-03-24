#pragma once
#include "../interfaces/IMedicalDevice.h"

class BloodPressureMonitor : public IMedicalDevice {
private:
    int batteryLevel;
public:
    BloodPressureMonitor(int initialBattery);
    VitalSigns getData() override;
    int getBatteryLevel() const override;
};