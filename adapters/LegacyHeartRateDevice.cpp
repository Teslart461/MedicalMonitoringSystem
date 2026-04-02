#include "LegacyHeartRateDevice.h"
#include <cstdlib>
#include <iostream>
#include <random>

int LegacyHeartRateDevice::readPulse() {
    std::cout << "[LegacyHeartRate] —читывание частоты сердечных сокращений...\n";

    static std::random_device rd;      // источник энтропии
    static std::mt19937 gen(rd());     // генератор
    static std::uniform_int_distribution<> dist(50, 160);

    return dist(gen);
}