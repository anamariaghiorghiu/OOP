#pragma once
#include "Car.h"
#include "Weather.h"

class Mercedes :
	public Car
{
public:
	Mercedes();
	double Race(double, Weather);
	void ShowBrand();
};

