#include "Fiat.h"

Fiat::Fiat() {
	name = new char[6];
	strcpy(name, "Seat");
	fuel_capacity = 90;
	fuel_consumption = 9;
	avg_speed[0] = 70;
	avg_speed[1] = 80;
	avg_speed[2] = 60;
}

float Fiat::Get_Speed(int weather) const {
	return avg_speed[weather];
}

float Fiat::Get_Fuel_Consumption() const {
	return fuel_consumption;
}

float Fiat::Get_Fuel_Capacity() const {
	return fuel_capacity;
}

char* Fiat::Get_Name() const {
	return name;
}