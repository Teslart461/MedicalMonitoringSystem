#pragma once
#include "../interfaces/IMedicalDevice.h"
#include "../devices/BloodPressureMonitor.h"
#include <memory>

class BloodPressureMonitorProxy : public IMedicalDevice {
private:
    std::shared_ptr<IMedicalDevice> realDevice;
    VitalSigns cache;
    int batteryLevel;

public:
    explicit BloodPressureMonitorProxy(std::shared_ptr<IMedicalDevice> device, int battery = 100);
    VitalSigns getData() override;
};