#include "TrafficSystem.h"

void TrafficSystem::addIntersection(Intersection* i) {
	intersections.push_back(i);
}

void TrafficSystem::processTurn() {
	for (Intersection* inter : intersections) {
		totalWaitTime +=
		/*inter->processTurn();*/

	}
}

void TrafficSystem::displayState() {
	for (Intersection* inter : intersections) {
		inter->display();
	}
}

int TrafficSystem::getTotalWaitTime() {
	return totalWaitTime;
}

int TrafficSystem::getProcessedVehicles() {
	return processedVehicles;
};

