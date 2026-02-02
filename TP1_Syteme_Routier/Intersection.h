#include "Road.h"

#ifndef Intersection_H
#define Intersection_H

#include <string>

class Intersection {
private:
	std::string name;
	//intersection type
	Road* northRoad;
	Road* southRoad;
	Road* eastRoad;
	Road* westRoad;
	//TrafficLightState northSouthLight : État du feu Nord - Sud(si applicable).
	//TrafficLightState eastWestLight : État du feu Est - Ouest(si applicable)
	int cycleCounter;
	int greenDuration;
	int maxGreenDuration;

public:
	void processTurn();
	void updateLight();
	void display();
 
};

#endif // !"ClassIntersection_H"
