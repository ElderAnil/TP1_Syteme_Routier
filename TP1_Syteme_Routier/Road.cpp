#include "Road.h"
#include <iostream>
Road::Road(std::string n, std::string d) {
	name = n;
	VehicleQueue file = VehicleQueue();
	direction = d;
}

void Road::addVehicle(Vehicle& v){
	file.enqueueVehicle(v);
}

Vehicle* Road::getNextVehicle() {
	return &this->file.dequeueVehicle();
}

void Road::increaseAllWaitTimes() {
	file.displayVehicle();
}

void Road::displayRoad() {
	std::cout << "Road name : " << name << std::endl;
	std::cout << "Direction : " << name << std::endl;
	std::cout << "Numbre of vehicles remaining : " << getVehicleCount() << std::endl;
}

int Road::getVehicleCount() {
	return file.getNumberVehicle();
}
