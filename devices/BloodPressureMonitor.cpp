#include "BloodPressureMonitor.h"
#include <cstdlib>
#include <iostream>
#include <random>

BloodPressureMonitor::BloodPressureMonitor(int initialBattery) : batteryLevel(initialBattery) {

}

VitalSigns BloodPressureMonitor::getData() {
    // Имитация расхода энергии на измерение
    batteryLevel -= 10;

    std::cout << "[BloodPressureMonitor] Считывание давления...\n";
    VitalSigns vs;

    static std::random_device rd;      // источник энтропии
    static std::mt19937 gen(rd());     // генератор
    static std::uniform_int_distribution<> sys(90, 200);
    static std::uniform_int_distribution<> dia(60, 110);

    vs.systolicPressure = sys(gen);
    vs.diastolicPressure = dia(gen);
    return vs;
}

int BloodPressureMonitor::getBatteryLevel() const {
    return batteryLevel;
}