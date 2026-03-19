#include "HeartRateMonitorProxy.h"
#include <iostream>

HeartRateMonitorProxy::HeartRateMonitorProxy(std::shared_ptr<IMedicalDevice> device, int battery)
    : realDevice(std::move(device)), batteryLevel(battery) {
}

VitalSigns HeartRateMonitorProxy::getData() {
    std::cout << "[Proxy] Запрос к датчику пульса. Заряд: " << batteryLevel << "%\n";
    if (batteryLevel < 10) {
        std::cout << "[Proxy Warning] Критически низкий заряд! Возвращаем кэшированные данные.\n";
        return cache;
    }

    // Логирование и кэширование
    cache = realDevice->getData();
    batteryLevel -= 5; // Имитация разряда
    return cache;
}