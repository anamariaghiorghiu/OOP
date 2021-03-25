#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
private:
	int NrOfCars;
	Weather Conditions;
	Car* Cars[10];
	double Length;
	double Time[10];

public:
	Circuit();
	void SetLength(double);
	void SetWeather(Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

