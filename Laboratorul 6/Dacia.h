#pragma once
#include "Car.h"
#include "Weather.h"

class Dacia:
	public Car
{
public:
	Dacia();
	double Race(double, Weather);
	void ShowBrand();
};

