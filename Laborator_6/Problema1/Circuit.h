#pragma once

#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Weather.h"
#include <iostream>


class Circuit
{
private:
	Car* cars[10];
	int CarCount, length;
	Weather weather;
	float Finishedcars[10];

public:
	Circuit();
	~Circuit();

	void SetLength(int len);
	void SetWeather(Weather w);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};

