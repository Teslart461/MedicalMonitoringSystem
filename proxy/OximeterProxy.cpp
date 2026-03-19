#include "OximeterProxy.h"
#include <iostream>

OximeterProxy::OximeterProxy(std::shared_ptr<IMedicalDevice> device, int battery)
    : realDevice(std::move(device)), batteryLevel(battery) {
}

VitalSigns OximeterProxy::getData() {
    std::cout << "[Proxy] Проверка соединения с пульсоксиметром. Заряд: " << batteryLevel << "%\n";
    if (batteryLevel < 10) {
        std::cout << "[Proxy Warning] Критически низкий заряд! Возвращаем кэшированные данные.\n";
        return cache;
    }

    // Логирование и кэширование
    cache = realDevice->getData();
    batteryLevel -= 3; // Имитация разряда
    return cache;
}