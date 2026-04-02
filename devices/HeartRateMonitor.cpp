#include "HeartRateMonitor.h"
#include <cstdlib>
#include <iostream>
#include <random>

HeartRateMonitor::HeartRateMonitor(int initialBattery) : batteryLevel(initialBattery) {
}

VitalSigns HeartRateMonitor::getData() {
    // Имитация расхода энергии на измерение
    batteryLevel -= 5;

    std::cout << "[HeartRateMonitor] Считывание пульса...\n";
    VitalSigns vs;

    static std::random_device rd;      // источник энтропии
    static std::mt19937 gen(rd());     // генератор
    static std::uniform_int_distribution<> dist(10, 250);

    vs.heartRate = dist(gen);
    return vs;
}

int HeartRateMonitor::getBatteryLevel() const {
    return batteryLevel;
}
