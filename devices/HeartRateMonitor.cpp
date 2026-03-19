#include "HeartRateMonitor.h"
#include <cstdlib>
#include <iostream>
#include <random>

VitalSigns HeartRateMonitor::getData() {
    std::cout << "[HeartRateMonitor] —читывание пульса...\n";
    VitalSigns vs;

    static std::random_device rd;      // источник энтропии
    static std::mt19937 gen(rd());     // генератор
    static std::uniform_int_distribution<> dist(50, 160);

    vs.heartRate = dist(gen);
    return vs;
}