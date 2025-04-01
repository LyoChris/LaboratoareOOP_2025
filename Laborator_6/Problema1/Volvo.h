#pragma once
#include "Car.h"

class Volvo : public Car {
public:
	Volvo();
	~Volvo() {};
	float Get_Speed(int weather) const override;
	float Get_Fuel_Consumption() const override;
	float Get_Fuel_Capacity() const override;
	char* Get_Name() const override;
};