#pragma once
#include "../models/VitalSigns.h"

class IMedicalDevice {
public:
    virtual ~IMedicalDevice() = default;
    virtual VitalSigns getData() = 0;
    // Новый метод: любое устройство должно уметь сообщать свой заряд
    virtual int getBatteryLevel() const = 0;
};