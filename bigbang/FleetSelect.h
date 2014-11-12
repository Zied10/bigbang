#pragma once
class FleetSelect
{
private:
	int id, price;
public:
	FleetSelect():id(0), price(0){}
	void setId(int newId);
	void setPrice(int fleetPrice);
	int getId();
	int getPrice();
};

