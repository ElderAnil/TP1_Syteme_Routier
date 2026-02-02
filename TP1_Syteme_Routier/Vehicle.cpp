#include "Vehicle.h"

#include <iostream>
#include <string>

void Vehicle::InitVehicle(std::string i, std::string t, int w, std::string d) {
	id = i;
	type = t;
	waitTime = w;
	destination = d;
}

void Vehicle::IncreaseWaitTime(int i) {
	waitTime += i;
}

void Vehicle::Display() const {
	std::cout << "######################" << std::endl;
	std::cout << " id : " << id << " " << std::endl;
	std::cout << " type : " << type << " " << std::endl;
	std::cout << " wait time : " << waitTime << " " << std::endl;
	std::cout << " destination : " << destination << " " << std::endl;
	std::cout << "######################" << std::endl;
};

