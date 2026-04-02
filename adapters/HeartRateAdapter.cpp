#include "HeartRateAdapter.h"

HeartRateAdapter::HeartRateAdapter(LegacyHeartRateDevice* dev) : device(dev) {

}

HeartRateAdapter::~HeartRateAdapter() {
    delete device;
}

VitalSigns HeartRateAdapter::getData() {
    VitalSigns vs{};

    // Преобразуем старый интерфейс в новый
    vs.heartRate = device->readPulse();

    return vs;
}

int HeartRateAdapter::getBatteryLevel() const {
    return 100;
}
