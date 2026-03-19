#pragma once
#include "../interfaces/IMedicalDevice.h"
#include "../devices/Oximeter.h"
#include <memory>

class OximeterProxy : public IMedicalDevice {
private:
    std::shared_ptr<IMedicalDevice> realDevice;
    VitalSigns cache;
    int batteryLevel;

public:
    explicit OximeterProxy(std::shared_ptr<IMedicalDevice> device, int battery = 100);
    VitalSigns getData() override;
};