#include "BloodPressureMonitorProxy.h"
#include <iostream>

BloodPressureMonitorProxy::BloodPressureMonitorProxy(std::shared_ptr<IMedicalDevice> device, int battery)
    : realDevice(std::move(device)), batteryLevel(battery) {
}

VitalSigns BloodPressureMonitorProxy::getData() {
    std::cout << "[Proxy] Запрос к тонометру. Заряд: " << batteryLevel << "%\n";
    if (batteryLevel < 10) {
        std::cout << "[Proxy Warning] Критически низкий заряд! Возвращаем кэшированные данные.\n";
        return cache;
    }

    // Логирование и кэширование
    cache = realDevice->getData();
    batteryLevel -= 10; // Имитация разряда
    return cache;
}