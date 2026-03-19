#pragma once
#include "../interfaces/IMedicalDevice.h"

class Oximeter : public IMedicalDevice {
public:
    VitalSigns getData() override;
};