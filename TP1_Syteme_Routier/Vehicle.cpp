#include "Vehicle.h"

#include <iostream>
#include <string>

Vehicle::Vehicle(std::string i, std::string t, std::string d): id(i), type(t), waitTime(0), destination(d) {}

void Vehicle::IncreaseWaitTime() {
	waitTime++;
}

void Vehicle::Display() const {
	std::cout << std::endl << " Id : " << id << " Type : " << type << " Wait time : " << waitTime << " Destination : " << destination;
};

