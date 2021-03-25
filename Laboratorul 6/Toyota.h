#pragma once
#include "Car.h"
#include "Weather.h"

class Toyota :
	public Car
{
public:
	Toyota();
	double Race(double, Weather);
	void ShowBrand();
};

