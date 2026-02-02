#include "Road.h"



Road::Road(std::string n, std::string d) {
	name = n;
	VehicleQueue file = VehicleQueue();
	direction = d;
}

void Road::addVehicle(Vehicle v){
	file.enqueueVehicle(v);
}

//Vehicle* Road::popNextVehicle() {
//	return &this->file.dequeueVehicle();
//}

//void Road::increaseAllWaitTimes() {
//	file.displayVehicle();
//}
//
//void Road::displayRoad() {
//}
//
//int Road::getVehicleCountInRoad() {
//}
