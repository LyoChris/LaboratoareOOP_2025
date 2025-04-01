#include "RangeRover.h"

RangeRover::RangeRover() {
	name = new char[6];
	strcpy(name, "RangeRover");
	fuel_capacity = 100;
	fuel_consumption = 12;
	avg_speed[0] = 70;
	avg_speed[1] = 80;
	avg_speed[2] = 70;
}

float RangeRover::Get_Speed(int weather) const {
	return avg_speed[weather];
}

float RangeRover::Get_Fuel_Consumption() const {
	return fuel_consumption;
}

float RangeRover::Get_Fuel_Capacity() const {
	return fuel_capacity;
}

char* RangeRover::Get_Name() const {
	return name;
}