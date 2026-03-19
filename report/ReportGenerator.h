#pragma once
#include "../interfaces/IReportSystem.h"
#include "../models/ElectronicHealthRecord.h"

class ReportGenerator : public IReportSystem {
public:
    void generateReport(const ElectronicHealthRecord& record) override;
    void printSpecificRecord(const ElectronicHealthRecord& record, size_t index);
};