#include "Mazda.h"
#include <iostream>

using namespace std;

Mazda::Mazda()
{
	FuelCapacity = 45;
	FuelConsumption = 0.15;
	AverageSpeed[Weather::Rain] = 50;
	AverageSpeed[Weather::Sunny] = 100;
	AverageSpeed[Weather::Snow] = 40;
}
double Mazda::Race(double distance, Weather v)
{
	if (FuelCapacity / FuelConsumption < distance)
		return -1;
	else
		return distance / AverageSpeed[v];
}
void Mazda::ShowBrand()
{
	cout << "Mazda";
}