#pragma once
#include "Weather.h"

class Car
{
protected:
	int FuelCapacity, AverageSpeed[3];
	double  FuelConsumption;
public:
	virtual double Race(double, Weather) = 0;
	virtual void ShowBrand() = 0;
};

