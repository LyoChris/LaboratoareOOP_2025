#include "Circuit.h"

Circuit::Circuit()
{
	CarCount = 0;
	length = 0;
}

Circuit::~Circuit()
{
	for (int i = 0; i < CarCount; i++)
		delete cars[i];
	CarCount = 0;
	length = 0;
}

void Circuit::SetLength(int len)
{
	length = len;
}

void Circuit::SetWeather(Weather w)
{
	weather = w;
}

void Circuit::AddCar(Car* c)
{
	cars[CarCount++] = c;
}

void Circuit::Race() {

	for (int i = 0;i < CarCount;i++)
	{
		float time = length / cars[i]->Get_Speed(weather);
		float fuel_needed = (cars[i]->Get_Fuel_Consumption()) * time;
		if (fuel_needed > cars[i]->Get_Fuel_Capacity())
		{
			Finishedcars[i] = 0;
		}
		else
		{
			Finishedcars[i] = time;
		}
	}
}

void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < CarCount; i++)
	{
		if (Finishedcars[i] > 0)
		{
			std::cout << cars[i]->Get_Name() << " finished in " << Finishedcars[i] << '\n';
		}
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	int k = 0;
	for (int i = 0; i < CarCount; i++)
	{
		if (Finishedcars[i] == 0)
		{
			std::cout << cars[i]->Get_Name() << " did not finish" << '\n';
			k++;
		}
	}
	if (k == 0) {
		std::cout << '\n';
		std::cout << "All cars finished!!" << '\n';
	}
}