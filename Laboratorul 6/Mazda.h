#pragma once
#include "Car.h"
#include "Weather.h"

class Mazda :
	public Car
{
public:
	Mazda();
	double Race(double, Weather);
	void ShowBrand();
};

