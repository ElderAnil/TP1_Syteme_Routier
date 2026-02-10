#include "Intersection.h"

void Intersection::processTurn() {
	if(type == IntersectionType::FIXED_LIGHT){
	
	}
	
	if(type == IntersectionType::FOUR_WAY_STOP) {

	}

	if(type == IntersectionType::PRIORITY_LIGHT) {

	}
}

void Intersection::updateLight() {

}

void Intersection::display() {
	std::cout << "Intersection name : " << name << std::endl;
	std::cout << "Status northRoad : " << std::endl; northRoad->displayRoad();
	std::cout << "Status southRoad : " << std::endl; southRoad->displayRoad();
	std::cout << "Status eastRoad : " << std::endl; eastRoad->displayRoad();
	std::cout << "Status westRoad : " << std::endl; westRoad->displayRoad();
}

void updateLights() {
    if (type == IntersectionType::SIMPLE) return;

    cycleCounter++;

    // Logique de changement de cycle simple
    if (cycleCounter >= greenDuration) {
        if (northSouthLight == TrafficLightState::GREEN) {
            northSouthLight = TrafficLightState::RED;
            eastWestLight = TrafficLightState::GREEN;
        }
        else {
            northSouthLight = TrafficLightState::GREEN;
            eastWestLight = TrafficLightState::RED;
        }
        cycleCounter = 0; // Réinitialisation du compteur
        std::cout << "[INFO] Changement de feux à l'intersection : " << name << std::endl;
    }
}