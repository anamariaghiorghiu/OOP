#include "Impartire.h"
#include <iostream>

using namespace std;

void Impartire::calculeaza(double x, double y)
{
	cout << nume << "(" << x << "," << y << ")=" << x / y;
}
Impartire::Impartire()
{
	nume = "Impartire";
}