#include "Intersection.h"

Intersection::Intersection(std::string name, IntersectionType intersectionType, int greenDuration, int maxGreenDuration) {
	this->name = name;
	this->type = intersectionType;
	this->greenDuration = greenDuration;
	this->maxGreenDuration = maxGreenDuration;
	this->cycleCounter = 0;

	northRoad = new Road("N", "Nord");
	southRoad = new Road("S", "South");
	eastRoad = new Road("E", "East");
	westRoad = new Road("W", "West");

	TrafficLightState northSouthLight = TrafficLightState::RED;
	TrafficLightState eastWestLight = TrafficLightState::RED;
}

void Intersection::processTurn() {
	updateLight();

	if (northSouthLight == TrafficLightState::GREEN) {
		northRoad->getNextVehicle();
		southRoad->getNextVehicle();
		eastRoad->increaseAllWaitTimes();
		westRoad->increaseAllWaitTimes();
	}
	else
	{
		northRoad->increaseAllWaitTimes();
		southRoad->increaseAllWaitTimes();
		eastRoad->getNextVehicle();
		westRoad->getNextVehicle();
	}
}

void Intersection::updateLight() {
	cycleCounter++;

	if(type == IntersectionType::PRIORITY_LIGHT){
		int numberNorthAndSouth = northRoad->getVehicleCount() + southRoad->getVehicleCount();
		int numberEastAndWesthRoad = eastRoad->getVehicleCount() + westRoad->getVehicleCount();

		if (numberNorthAndSouth > numberEastAndWesthRoad) {
			eastWestLight = TrafficLightState::RED; 
			northSouthLight = TrafficLightState::GREEN;
		}
		else{
			eastWestLight = TrafficLightState::GREEN; 
			northSouthLight = TrafficLightState::RED;
		}

		greenDuration = 2;
		maxGreenDuration = 5;
	}
	
	if(type == IntersectionType::FIXED_LIGHT) {

		if (northSouthLight == TrafficLightState::GREEN)
			northSouthLight = TrafficLightState::RED;
		else
			northSouthLight = TrafficLightState::GREEN;


		if (eastWestLight == TrafficLightState::GREEN)
			eastWestLight = TrafficLightState::RED;
		else
			eastWestLight = TrafficLightState::GREEN;

			greenDuration = 3;
			maxGreenDuration = 3;
	}

	if(type == IntersectionType::FOUR_WAY_STOP) {
			
			int n = northRoad->getNextVehicle()->waitTime;
			int s = southRoad->getNextVehicle()->waitTime;
			int e = eastRoad->getNextVehicle()->waitTime;
			int w = westRoad->getNextVehicle()->waitTime;
			
			if ((n + s) > (e + w) ){
				eastWestLight = TrafficLightState::RED;
				northSouthLight = TrafficLightState::GREEN;
			}
			else {
				eastWestLight = TrafficLightState::GREEN;
				northSouthLight = TrafficLightState::RED;
			}

		greenDuration = 1;
		maxGreenDuration = 1;
	}
}


void Intersection::display() {
	std::cout << "Intersection name : " << name << std::endl;
	std::cout << "Status northRoad : " << std::endl; northRoad->displayRoad();
	std::cout << "Status southRoad : " << std::endl; southRoad->displayRoad();
	std::cout << "Status eastRoad : " << std::endl; eastRoad->displayRoad();
	std::cout << "Status westRoad : " << std::endl; westRoad->displayRoad();
}
