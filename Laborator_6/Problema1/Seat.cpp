#include "Seat.h"

Seat::Seat() {
	name = new char[6];
	strcpy(name, "Seat");
	fuel_capacity = 80;
	fuel_consumption = 10;
	avg_speed[0] = 70;
	avg_speed[1] = 90;
	avg_speed[2] = 50;
}

float Seat::Get_Speed(int weather) const {
	return avg_speed[weather];
}

float Seat::Get_Fuel_Consumption() const {
	return fuel_consumption;
}

float Seat::Get_Fuel_Capacity() const {
	return fuel_capacity;
}

char* Seat::Get_Name() const {
	return name;
}