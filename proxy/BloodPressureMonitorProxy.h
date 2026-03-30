#pragma once
#include "../interfaces/IMedicalDevice.h"
#include "../devices/BloodPressureMonitor.h"

class BloodPressureMonitorProxy : public IMedicalDevice {
private:
    IMedicalDevice* realDevice; //Убрал shared_ptr
    VitalSigns cache;

public:
    BloodPressureMonitorProxy(IMedicalDevice* device);
    ~BloodPressureMonitorProxy() override;
    int getBatteryLevel() const override;
    VitalSigns getData() override;
};