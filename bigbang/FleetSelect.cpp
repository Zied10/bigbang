#include "FleetSelect.h"


void FleetSelect::setId(int newId){
	id = newId;
}

int FleetSelect::getId(){
	return id;
}

void FleetSelect::setPrice(int fleetPrice){
	price = fleetPrice;
}

int FleetSelect::getPrice(){
	return price;
}
FleetSelect::~FleetSelect()
{
}
