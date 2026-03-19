#include "Oximeter.h"
#include <iostream>
#include <cstdlib>
#include <random>

VitalSigns Oximeter::getData() {
    std::cout << "[Oximeter] —читывание сатурации...\n";
    VitalSigns vs;

    static std::random_device rd;      // источник энтропии
    static std::mt19937 gen(rd());     // генератор
    static std::uniform_int_distribution<> dist(85, 99);

    vs.oxygenSaturation = dist(gen);
    return vs;
}