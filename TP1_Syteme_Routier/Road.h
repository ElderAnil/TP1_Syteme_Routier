#include "VehicleQueue.h"

#ifndef Road_H
#define Road_H
#include <string>
#include <queue>


class Road {
private:
	std::string name;
	VehicleQueue file;
	std::string direction;

public:
	Road(std::string, std::string);
	void addVehicle(Vehicle);
	Vehicle* popNextVehicle();
	void increaseAllWaitTimes();
	void displayRoad();
	int getVehicleCountInRoad();
};

 

#endif // !ClassRoad_H
