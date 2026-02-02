#include "Vehicle.h"

#ifndef VehicleeQueue_H
#define VehicleQueue_H
#include <fstream>
#include <sstream>
#include <string>
#define Max_Vehicul_Per_Road 5


class VehicleQueue {
private:
	Vehicle arrVehicle[Max_Vehicul_Per_Road];
	int frontIndex;
	int rearIndex;
	int size;

public:
	VehicleQueue(); 
	void enqueueVehicle(Vehicle&);
	Vehicle dequeueVehicle();
	void peekVehicle();
	bool isEmpty() const;
	int getNumberVehicle() const;
	void displayVehicle();
};



#endif
