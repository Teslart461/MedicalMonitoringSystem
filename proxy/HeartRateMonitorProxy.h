#pragma once
#include "../interfaces/IMedicalDevice.h"
#include "../devices/HeartRateMonitor.h"

class HeartRateMonitorProxy : public IMedicalDevice {
private:
    IMedicalDevice* realDevice; //Убрал shared_ptr
    VitalSigns cache;

public:
    HeartRateMonitorProxy(IMedicalDevice* device);
    ~HeartRateMonitorProxy() override;
    int getBatteryLevel() const override;
    VitalSigns getData() override;
};