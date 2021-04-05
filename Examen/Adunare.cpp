#include "Adunare.h"
#include <iostream>

using namespace std;

void Adunare::calculeaza(double x, double y)
{
	cout << nume << "(" << x << "," << y << ")=" << x + y;
}
Adunare::Adunare()
{
	nume = "Adunare";
}