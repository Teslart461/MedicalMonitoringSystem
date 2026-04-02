#include "BloodPressureAdapter.h"

BloodPressureAdapter::BloodPressureAdapter(LegacyBloodPressureDevice* dev) : device(dev) {

}

BloodPressureAdapter::~BloodPressureAdapter() {
    delete device;
}

VitalSigns BloodPressureAdapter::getData() {
    VitalSigns vs{};

    // Преобразуем старый интерфейс в новый
    vs.systolicPressure = device->getSystolic();
    vs.diastolicPressure = device->getDiastolic();

    return vs;
}

int BloodPressureAdapter::getBatteryLevel() const {
    return 100;
}