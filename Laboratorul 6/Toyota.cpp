#include "Toyota.h"
#include <iostream>

using namespace std;

Toyota::Toyota()
{
	FuelCapacity = 25;
	FuelConsumption = 0.3;
	AverageSpeed[Weather::Rain] = 110;
	AverageSpeed[Weather::Sunny] = 170;
	AverageSpeed[Weather::Snow] = 90;
}
double Toyota::Race(double distance, Weather v)
{
	if (FuelCapacity / FuelConsumption < distance)
		return -1;
	else
		return distance / AverageSpeed[v];
}
void Toyota::ShowBrand()
{
	cout << "Toyota";
}