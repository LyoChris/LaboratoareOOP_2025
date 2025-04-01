#pragma once
#include "Car.h"

class Seat : public Car {
public:
	Seat();
	~Seat() {};
	float Get_Speed(int weather) const override;
	float Get_Fuel_Consumption() const override;
	float Get_Fuel_Capacity() const override;
	char* Get_Name() const override;
};