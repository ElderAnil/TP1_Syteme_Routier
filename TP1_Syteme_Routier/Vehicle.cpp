#include "Vehicle.h"

#include <iostream>
#include <string>

Vehicle::Vehicle(std::string i, std::string t, int w, std::string d): id(i), type(t), waitTime(w), destination(d) {}

void Vehicle::IncreaseWaitTime(int i) {
	waitTime += i;
}

void Vehicle::Display() const {

	std::cout << std::endl << " Id : " << id << " Type : " << type << " Wait time : " << waitTime << " Destination : " << destination << std::endl;
};

