#pragma once
#include "../interfaces/IMedicalDevice.h"

class Oximeter : public IMedicalDevice {
private:
    int batteryLevel;
public:
    Oximeter(int initialBattery);
    VitalSigns getData() override;
    int getBatteryLevel() const override;
};