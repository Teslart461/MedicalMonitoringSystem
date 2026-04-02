#include "DiagnosisDecorator.h"

DiagnosisDecorator::DiagnosisDecorator(IDiagnosis* diagnosis) : wrapped(diagnosis) {

}

DiagnosisDecorator::~DiagnosisDecorator() {
	delete wrapped;
}

bool DiagnosisDecorator::check(const VitalSigns& data) {
	return wrapped->check(data);
}

VitalSigns DiagnosisDecorator::process(const VitalSigns& data) {
	return wrapped->process(data);
}

bool DiagnosisDecorator::isCritical() const {
	return wrapped->isCritical();
}