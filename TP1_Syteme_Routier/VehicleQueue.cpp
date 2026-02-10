#include "VehicleQueue.h"


#include <iostream>

VehicleQueue::VehicleQueue(){
	frontIndex = 0;
	rearIndex = -1;
	size = 0;
}

void VehicleQueue::enqueueVehicle(Vehicle& v) {
	if (size == Max_Vehicul_Per_Road) {
		std::cout << "The road is too full !" << std::endl;
		return;
	}
	
	rearIndex = (rearIndex + 1) % Max_Vehicul_Per_Road;
	arrVehicle[rearIndex] = v;
	size++;
}

Vehicle VehicleQueue::dequeueVehicle() {
	if (isEmpty()) {
		throw std::overflow_error("The road is empty ! ");
	}
	
	Vehicle temp;
	temp = arrVehicle[frontIndex];

	frontIndex = (frontIndex + 1) % Max_Vehicul_Per_Road;
	size--;
	
	return temp; 
}

void VehicleQueue::peekVehicle() {
	arrVehicle[frontIndex].Display();
}

bool VehicleQueue::isEmpty() const {
	return size == 0;
}

int VehicleQueue::getNumberVehicle() const {
	return size;
}

void VehicleQueue::displayVehicle() {
	for (int i = 0; i <= size; i++) {
		arrVehicle[i].Display(); 
		arrVehicle[i].IncreaseWaitTime(1); //à verifier et changer 
	}
}