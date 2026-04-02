#include "OximeterAdapter.h"

OximeterAdapter::OximeterAdapter(LegacyOximeter* dev) : device(dev) {

}

OximeterAdapter::~OximeterAdapter() {
	delete device;
}

VitalSigns OximeterAdapter::getData() {
	VitalSigns vs{};

	// Преобразуем старый интерфейс в новый
	vs.oxygenSaturation = device->readSaturation();

	return vs;
}

int OximeterAdapter::getBatteryLevel() const {
	return 100;
}