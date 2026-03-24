#include "EmergencyNotifier.h"
#include <iostream>

void EmergencyNotifier::sendAlert(const std::string& message) {
    std::cout << "\n[ÂÍÈÌÀÍÈÅ! ÝÊÑÒÐÅÍÍÎÅ ÓÂÅÄÎÌËÅÍÈÅ]\n"
        << "-> " << message << "\n"
        << "Òðåáóåòñÿ íåìåäëåííîå âìåøàòåëüñòâî!\n";
}