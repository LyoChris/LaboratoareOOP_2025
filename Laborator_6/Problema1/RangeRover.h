#pragma once
#include "Car.h"

class RangeRover : public Car {
public:
	RangeRover();
	~RangeRover() {};
	float Get_Speed(int weather) const override;
	float Get_Fuel_Consumption() const override;
	float Get_Fuel_Capacity() const override;
	char* Get_Name() const override;
};