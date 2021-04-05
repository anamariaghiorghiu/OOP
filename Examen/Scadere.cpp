#include "Scadere.h"
#include <iostream>

using namespace std;

void Scadere::calculeaza(double x, double y)
{
	cout << nume << "(" << x << "," << y << ")=" << x - y;
}
Scadere::Scadere()
{
	nume = "Scadere";
}