#include "Road.h"
#include <iostream>
Road::Road(std::string n, std::string d) {
	name = n;
	direction = d;
	VehicleQueue file = VehicleQueue();
}

void Road::addVehicle(Vehicle& v){
	file.enqueueVehicle(v);
}

Vehicle* Road::getNextVehicle() {
	return &file.peekVehicle();
}

void Road::increaseAllWaitTimes() {
	file.displayVehicle();
}

void Road::displayRoad() {
	std::cout << "Road name : " << name << std::endl;
	std::cout << "Direction : " << direction << std::endl;
	std::cout << "Numbre of vehicles remaining : " << getVehicleCount() << std::endl;
}

int Road::getVehicleCount() {
	return file.getNumberVehicle();
}
