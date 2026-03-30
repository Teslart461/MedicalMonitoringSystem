#pragma once
#include "../interfaces/IPatientRecord.h"
#include <vector>

class ElectronicHealthRecord : public IPatientRecord {
private:
    std::vector<VitalSigns> history;
public:
    void addRecord(const VitalSigns& data);

    // Реализация методов интерфейса IPatientRecord
    void saveData(const VitalSigns& data) override;
    std::vector<VitalSigns> getHistory() const override;

    // Получить общее количество записей
    size_t getRecordsCount() const;

    // Получить конкретную запись по номеру
    VitalSigns getRecordByIndex(size_t index) const;
};