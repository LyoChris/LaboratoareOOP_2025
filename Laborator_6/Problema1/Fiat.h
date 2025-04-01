#pragma once
#include "Car.h"

class Fiat : public Car {
public:
	Fiat();
	~Fiat() {};
	float Get_Speed(int weather) const override;
	float Get_Fuel_Consumption() const override;
	float Get_Fuel_Capacity() const override;
	char* Get_Name() const override;
};