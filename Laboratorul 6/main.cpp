#include <iostream>
#include "Car.h"
#include "Dacia.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Toyota.h"
#include "Circuit.h"

using namespace std;

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	c.Race();
	c.ShowFinalRanks(); 
	c.ShowWhoDidNotFinish(); 
	return 0;
}