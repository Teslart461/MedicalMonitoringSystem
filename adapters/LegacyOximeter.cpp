#include "LegacyOximeter.h"
#include <cstdlib>
#include <iostream>
#include <random>

int LegacyOximeter::readSaturation() {
    std::cout << "[LegacyOximeter] —читывание сатурации...\n";

    static std::random_device rd;      
    static std::mt19937 gen(rd());     
    static std::uniform_int_distribution<> dist(85, 100);

    return dist(gen);
}
