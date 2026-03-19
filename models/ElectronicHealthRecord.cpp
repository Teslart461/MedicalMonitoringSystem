#include "ElectronicHealthRecord.h"

void ElectronicHealthRecord::addRecord(const VitalSigns& data) {
    saveData(data);
}

void ElectronicHealthRecord::saveData(const VitalSigns& data) {
    history.push_back(data);
}

std::vector<VitalSigns> ElectronicHealthRecord::getHistory() const {
    return history;
}

size_t ElectronicHealthRecord::getRecordsCount() const {
    return history.size();
}

VitalSigns ElectronicHealthRecord::getRecordByIndex(size_t index) const {
    if (index < history.size()) return history[index];
    return VitalSigns(); // Или выбросить исключение
}
