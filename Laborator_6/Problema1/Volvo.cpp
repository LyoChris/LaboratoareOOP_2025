#include "Volvo.h"

Volvo::Volvo() {
	name = new char[6];
	strcpy(name, "Volvo");
	fuel_capacity = 90;
	fuel_consumption = 9;
	avg_speed[0] = 70;
	avg_speed[1] = 100;
	avg_speed[2] = 60;
}

float Volvo::Get_Speed(int weather) const {
	return avg_speed[weather];
}

float Volvo::Get_Fuel_Consumption() const {
	return fuel_consumption;
}

float Volvo::Get_Fuel_Capacity() const {
	return fuel_capacity;
}

char* Volvo::Get_Name() const {
	return name;
}