#include "Dacia.h"
#include <iostream>

using namespace std;

Dacia::Dacia()
{
	FuelCapacity = 40;
	FuelConsumption = 0.1;
	AverageSpeed[Weather::Rain] = 70;
	AverageSpeed[Weather::Sunny] = 100;
	AverageSpeed[Weather::Snow] = 50;
}
double Dacia::Race(double distance, Weather v)
{
	if (FuelCapacity / FuelConsumption < distance)
		return -1;
	else
		return distance / AverageSpeed[v];
}
void Dacia::ShowBrand()
{
	cout << "Dacia";
}