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
	void addVehicle(Vehicle&);
	Vehicle* getNextVehicle();
	void increaseAllWaitTimes();
	void displayRoad();
	int getVehicleCount();
};

 

#endif // !ClassRoad_H
