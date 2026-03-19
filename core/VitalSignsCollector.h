#pragma once
#include "../interfaces/IMedicalDevice.h"
#include <vector>
#include <memory>

class VitalSignsCollector {
private:
    std::vector<std::shared_ptr<IMedicalDevice>> devices;

public:
    void addDevice(std::shared_ptr<IMedicalDevice> device);
    VitalSigns collectData();
};