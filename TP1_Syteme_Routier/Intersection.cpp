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
}

int Intersection::processTurn() {
	int passedVehicle;
	
	updateLight();

	do{
		if (northSouthLight == TrafficLightState::GREEN) {
			northRoad->getNextVehicle();
			southRoad->getNextVehicle();
			eastRoad->increaseAllWaitTimes();
			westRoad->increaseAllWaitTimes();
			northRoad->increaseAllWaitTimes();
			southRoad->increaseAllWaitTimes();
			cycleCounter++;
		}
		else if(eastWestLight == TrafficLightState::GREEN)
		{
			eastRoad->getNextVehicle();
			westRoad->getNextVehicle();
			eastRoad->increaseAllWaitTimes();
			westRoad->increaseAllWaitTimes();
			northRoad->increaseAllWaitTimes();
			southRoad->increaseAllWaitTimes();
			cycleCounter++;
		}
		else if (type == IntersectionType::FOUR_WAY_STOP) {
			
			Road* longestWaiting = northRoad;

			for (int i = 0; i < 4; i++) {
				if (southRoad->getNextVehicle()->waitTime > longestWaiting->getNextVehicle()->waitTime)
					longestWaiting = southRoad;
				if (eastRoad->getNextVehicle()->waitTime > longestWaiting->getNextVehicle()->waitTime)
					longestWaiting = eastRoad;
				if (westRoad->getNextVehicle()->waitTime > longestWaiting->getNextVehicle()->waitTime)
					longestWaiting = westRoad;

				longestWaiting->getNextVehicle();

				if (northRoad != longestWaiting)
					northRoad->increaseAllWaitTimes();
				if(southRoad != longestWaiting)
					southRoad->increaseAllWaitTimes();
				if(eastRoad != longestWaiting)
					eastRoad->increaseAllWaitTimes();
				if(westRoad != longestWaiting)
					westRoad->increaseAllWaitTimes();
			}
			cycleCounter++;
		}

	} while (!(greenDuration == cycleCounter));

	return passedVehicle;
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
		cycleCounter = 0;
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
			cycleCounter = 0;
	}

	if(type == IntersectionType::FOUR_WAY_STOP) {
		eastWestLight = TrafficLightState::RED;
		northSouthLight = TrafficLightState::RED;
		greenDuration = 1;
		cycleCounter = 0;
	}
}


void Intersection::display() {
	std::cout << "Intersection name : " << name << std::endl;
	std::cout << "Status northRoad : " << std::endl; northRoad->displayRoad();
	std::cout << "Status southRoad : " << std::endl; southRoad->displayRoad();
	std::cout << "Status eastRoad : " << std::endl; eastRoad->displayRoad();
	std::cout << "Status westRoad : " << std::endl; westRoad->displayRoad();
}
