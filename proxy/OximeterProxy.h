#pragma once
#include "../interfaces/IMedicalDevice.h"
#include "../devices/Oximeter.h"
#include <memory>

class OximeterProxy : public IMedicalDevice {
private:
    IMedicalDevice* realDevice; //Убрал shared_ptr
    VitalSigns cache;

public:
    OximeterProxy(IMedicalDevice* device);
    ~OximeterProxy() override;
    int getBatteryLevel() const override;
    VitalSigns getData() override;
};