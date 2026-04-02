#pragma once

#include "../interfaces/IMedicalDevice.h"
#include "LegacyOximeter.h"
#include "../models/VitalSigns.h"

class OximeterAdapter : public IMedicalDevice {
private:
    LegacyOximeter* device;

public:
    OximeterAdapter(LegacyOximeter* dev);
    ~OximeterAdapter();
    VitalSigns getData() override;
    int getBatteryLevel() const;
};