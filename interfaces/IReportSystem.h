#pragma once
#include <string>

class ElectronicHealthRecord;

class IReportSystem {
public:
    virtual ~IReportSystem() = default;
    // Компромисс по ISP: пустые реализации по умолчанию
    virtual void generateReport(const ElectronicHealthRecord& record) {}
    virtual void sendAlert(const std::string& message) {}
};