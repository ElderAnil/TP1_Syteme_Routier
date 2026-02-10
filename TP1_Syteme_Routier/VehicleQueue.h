#include "Vehicle.h"

#ifndef VehicleeQueue_H
#define VehicleQueue_H


#include <string>

#define Max_Vehicul_Per_Road 100

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
	Vehicle& peekVehicle();
	bool isEmpty() const;
	int getNumberVehicle() const;
	void displayVehicle();
};

#endif
