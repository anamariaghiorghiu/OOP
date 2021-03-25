#include "Ford.h"
#include <iostream>

using namespace std;

Ford::Ford()
{
	FuelCapacity = 50;
	FuelConsumption = 0.2;
	AverageSpeed[Weather::Rain] = 80;
	AverageSpeed[Weather::Sunny] = 120;
	AverageSpeed[Weather::Snow] = 60;
}
double Ford::Race(double distance, Weather v)
{
	if (FuelCapacity / FuelConsumption < distance)
		return -1;
	else
		return distance / AverageSpeed[v];
}
void Ford::ShowBrand()
{
	cout << "Ford";
}