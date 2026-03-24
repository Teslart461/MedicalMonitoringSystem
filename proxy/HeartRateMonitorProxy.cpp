#include "HeartRateMonitorProxy.h"
#include <iostream>

HeartRateMonitorProxy::HeartRateMonitorProxy(IMedicalDevice* device) : realDevice(device) {

}

HeartRateMonitorProxy::~HeartRateMonitorProxy() {
	delete realDevice;
}

int HeartRateMonitorProxy::getBatteryLevel() const {
	return realDevice->getBatteryLevel();
}

VitalSigns HeartRateMonitorProxy::getData() {
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
