#pragma once
#include "../interfaces/IMedicalDevice.h"
#include <vector>

class VitalSignsCollector {
private:
    std::vector<IMedicalDevice*> devices; // Массив указателей

public:
    ~VitalSignsCollector();
    void addDevice(IMedicalDevice* device);
    VitalSigns collectData();
};