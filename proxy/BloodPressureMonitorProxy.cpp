#include "BloodPressureMonitorProxy.h"
#include <iostream>

BloodPressureMonitorProxy::BloodPressureMonitorProxy(IMedicalDevice* device) : realDevice(device) {

}

BloodPressureMonitorProxy::~BloodPressureMonitorProxy() {
	delete realDevice;
}

int BloodPressureMonitorProxy::getBatteryLevel() const {
	return realDevice->getBatteryLevel();
}

VitalSigns BloodPressureMonitorProxy::getData() {
    // Проверяем заряд РЕАЛЬНОГО устройства
    if (realDevice->getBatteryLevel() > 10) {
        // Если энергии хватает, делаем измерение и обновляем кэш
        cache = realDevice->getData();
        return cache;
    }
    else {
        // Если прибор сел, спасаем ситуацию — отдаем старые данные
        std::cout << "[Proxy] Внимание! Низкий заряд датчика. Возвращаю кэшированные данные.\n";
        return cache;
    }
}
