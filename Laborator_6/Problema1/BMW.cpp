#include "BMW.h"

BMW::BMW() {
	name = new char[6];
	strcpy(name, "BMW");
	fuel_capacity = 80;
	fuel_consumption = 12;
	avg_speed[0] = 50;
	avg_speed[1] = 110;
	avg_speed[2] = 60;
}

float BMW::Get_Speed(int weather) const {
	return avg_speed[weather];
}

float BMW::Get_Fuel_Consumption() const {
	return fuel_consumption;
}

float BMW::Get_Fuel_Capacity() const {
	return fuel_capacity;
}

char* BMW::Get_Name() const {
	return name;
}