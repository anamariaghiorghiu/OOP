#include "Mercedes.h"
#include <iostream>

using namespace std;

Mercedes::Mercedes()
{
	FuelCapacity = 30;
	FuelConsumption = 0.31;
	AverageSpeed[Weather::Rain] = 100;
	AverageSpeed[Weather::Sunny] = 150;
	AverageSpeed[Weather::Snow] = 90;
}
double Mercedes::Race(double distance, Weather v)
{
	if (FuelCapacity / FuelConsumption < distance)
		return -1;
	else
		return distance / AverageSpeed[v];
}
void Mercedes::ShowBrand()
{
	cout << "Mercedes";
}