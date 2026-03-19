#pragma once
#include "../interfaces/IReportSystem.h"
#include "../models/ElectronicHealthRecord.h"

class EmergencyNotifier : public IReportSystem {
public:
    void sendAlert(const std::string& message) override;
};