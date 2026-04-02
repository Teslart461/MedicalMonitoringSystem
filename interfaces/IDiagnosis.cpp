#include "IDiagnosis.h"

bool IDiagnosis::isCritical() const {
	return false;
}

VitalSigns IDiagnosis::process(const VitalSigns& data) {
	return data;
}