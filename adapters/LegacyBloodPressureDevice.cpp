#include "LegacyBloodPressureDevice.h"
#include <cstdlib>
#include <iostream>
#include <random>

int LegacyBloodPressureDevice::getSystolic() {
    std::cout << "[LegacyBloodPressure] —читывание диастолического давлени€...\n";

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> sys(60, 100);

    return sys(gen);
}

int LegacyBloodPressureDevice::getDiastolic() {
    std::cout << "[LegacyBloodPressure] —читывание систолического давлени€...\n";

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dia(90, 200);

    return dia(gen);
}
