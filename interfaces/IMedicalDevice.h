#pragma once
#include "../models/VitalSigns.h"

class IMedicalDevice {
public:
    virtual ~IMedicalDevice() = default;
    virtual VitalSigns getData() = 0;
};