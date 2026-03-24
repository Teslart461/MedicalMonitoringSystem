#pragma once
#include "../interfaces/IMedicalDevice.h"
#include <vector>
#include <memory>

class VitalSignsCollector {
private:
    std::vector<IMedicalDevice*> devices; // Массив указателей

public:
    ~VitalSignsCollector();
    void addDevice(IMedicalDevice* device);
    VitalSigns collectData();
};