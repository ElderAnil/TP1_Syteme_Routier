#ifndef Intersection_H
#define Intersection_H

#include <string>
#include <iostream>
#include "Road.h"

enum class TrafficLightState {
	RED, GREEN, YELLOW ///Optionnel ?? 
};

enum class IntersectionType {
	PRIORITY_LIGHT, FIXED_LIGHT, FOUR_WAY_STOP
};

class Intersection {
private:
	std::string name;
	IntersectionType type;

	Road* northRoad;
	Road* southRoad;
	Road* eastRoad;
	Road* westRoad;

	TrafficLightState northSouthLight;
	TrafficLightState eastWestLight;

	int cycleCounter;
	int greenDuration;
	int maxGreenDuration;

public:
	void processTurn();
	void updateLight();
	void display();
 
};

#endif // !"ClassIntersection_H"
