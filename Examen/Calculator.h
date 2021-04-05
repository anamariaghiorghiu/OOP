#pragma once
#include "Operatie.h"
class Calculator
{
	Operatie* p[10];
	int nr_op;
public:
	Calculator();
	~Calculator();
	Calculator& operator +=(Operatie*);
	Calculator& operator -=(const char*);
	void Compute(double, double);
	operator int()const;
	bool operator[](const char*);
};

