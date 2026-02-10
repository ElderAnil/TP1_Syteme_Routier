#include "Intersection.h"
#ifndef TrafficSystem_h
#define TrafficSystem_h

#include <vector>
class TrafficSystem {

private:
	std::vector<Intersection*> intersections;
	int totalWaitTime;
	int processedVehicles;

public:
	void addIntersection(Intersection* intersection);
	void processTurn();
	void displayState();
	int getTotalWaitTime();
	int getProcessedVehicles();
};

#endif
