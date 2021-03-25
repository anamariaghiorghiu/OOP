#pragma once
#include "Car.h"
#include "Weather.h"

class Ford :
	public Car
{
public:
	Ford();
	double Race(double, Weather);
	void ShowBrand();
};

