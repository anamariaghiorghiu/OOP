#include "Circuit.h"
#include <iomanip>
#include <iostream>

using namespace std;

Circuit::Circuit()
{
	NrOfCars = 0;
	Length = 0;
	Conditions = Sunny;

}
void Circuit::SetLength(double Length)
{
	this->Length = Length;
}
void Circuit::SetWeather(Weather Conditions)
{
	this->Conditions = Conditions;
}
void Circuit::AddCar(Car* p)
{
	if (NrOfCars < 10)
	{
		Cars[NrOfCars] = p;
		NrOfCars++;
	}
}
void Circuit::Race()
{
	int i;
	for (i = 0; i < NrOfCars; i++)
		Time[i] = Cars[i]->Race(Length, Conditions);
}
void Circuit::ShowFinalRanks()
{
	int i,j;
	double aux;
	Car* temp;
	bool ordonat, gasit;
	do
	{
		ordonat = true;
		for(i=0; i<NrOfCars-1; i++)
			if (Time[i] > Time[i + 1])
			{
				ordonat = false;
				aux = Time[i];
				Time[i] = Time[i + 1];
				Time[i + 1] = aux;
				temp = Cars[i];
				Cars[i] = Cars[i + 1];
				Cars[i + 1] = temp;
			}
	} while (!ordonat);
	i = 0;
	gasit = false;
	while (!gasit && i < NrOfCars)
		if (Time[i] >= 0)
			gasit = true;
		else
			i++;
	cout << "RANK BRAND     TIME" << endl;
	for (j = i; j < NrOfCars; j++)
	{
		cout.width(5);
		cout << left << j - i + 1;
		cout.width(10);
		cout << left;
		Cars[j]->ShowBrand();
		cout.width(5);
		cout << fixed << setprecision(2) << Time[j];
		cout << endl;
	}
}
void Circuit::ShowWhoDidNotFinish()
{
	int i;
	cout << "Cars that did not finish:" << endl;
	for (i = 0; i < NrOfCars; i++)
		if (Time[i] < 0)
		{
			Cars[i]->ShowBrand();
			cout << endl;
		}
}