#pragma once
#include "../interfaces/IMedicalDevice.h"
#include "../devices/HeartRateMonitor.h"
#include <memory>

class HeartRateMonitorProxy : public IMedicalDevice {
private:
    std::shared_ptr<IMedicalDevice> realDevice;
    VitalSigns cache;
    int batteryLevel;

public:
    explicit HeartRateMonitorProxy(std::shared_ptr<IMedicalDevice> device, int battery = 100);
    VitalSigns getData() override;
};