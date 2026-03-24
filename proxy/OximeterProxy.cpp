#include "OximeterProxy.h"
#include <iostream>

OximeterProxy::OximeterProxy(IMedicalDevice* device) : realDevice(device) {

}

OximeterProxy::~OximeterProxy() {
	delete realDevice;
}

int OximeterProxy::getBatteryLevel() const {
	return realDevice->getBatteryLevel();
}

VitalSigns OximeterProxy::getData() {
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
