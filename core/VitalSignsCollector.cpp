#include "VitalSignsCollector.h"

VitalSignsCollector::~VitalSignsCollector() {
    for (auto device : devices) {
        delete device; //  оллектор удал€ет все устройства
    }
}

void VitalSignsCollector::addDevice(IMedicalDevice* device) {
    devices.push_back(device);
}

VitalSigns VitalSignsCollector::collectData() {
    VitalSigns aggregatedData{};
    for (const auto& device : devices) {
        VitalSigns current = device->getData();
        // јгрегируем данные (записываем только те, что не равны 0)
        if (current.heartRate > 0) aggregatedData.heartRate = current.heartRate;
        if (current.systolicPressure > 0) aggregatedData.systolicPressure = current.systolicPressure;
        if (current.diastolicPressure > 0) aggregatedData.diastolicPressure = current.diastolicPressure;
        if (current.oxygenSaturation > 0) aggregatedData.oxygenSaturation = current.oxygenSaturation;
    }
    return aggregatedData;
}