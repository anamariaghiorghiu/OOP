#define _CRT_SECURE_NO_WARNINGS
#include "Calculator.h"
#include <iostream>
#include <cstdlib>

using namespace std; 

Calculator::Calculator()
{
	nr_op = 0;
}
Calculator::~Calculator()
{
	int i;
	for (i = 0; i < nr_op; i++)
		free(p[i]);
}
void Calculator::Compute(double x, double y)
{
	int i;
	for (i = 0; i < nr_op; i++)
	{
		p[i]->calculeaza(x,y);
		cout << endl;
	}
}
Calculator& Calculator::operator += (Operatie* o)
{
	int i;
	bool gasit;
	char nume[100], nume_o[100];
	gasit = false;
	o->getNume(nume_o);
	for (i = 0; i < nr_op; i++)
	{
		p[i]->getNume(nume);
		if (strcmp(nume, nume_o)==0)
			gasit = true;
	}
	if (!gasit)
	{
		p[nr_op] = o;
		nr_op++;
	}
	return *this;
}
Calculator::operator int()const
{
	return nr_op;
}
Calculator& Calculator::operator -=(const char*nume_o)
{
	int i,j;
	char nume[100];
	for (i = 0; i < nr_op; i++)
	{
		p[i]->getNume(nume);
		if (strcmp(nume,nume_o) == 0)
		{
			for (j = i + 1; j < nr_op; j++)
				p[j - 1] = p[j];
			nr_op--;
		}
	}
	return *this;
}
bool Calculator:: operator[](const char*nume_o)
{
	int i;
	char nume[100];
	for (i = 0; i < nr_op; i++)
	{
		p[i]->getNume(nume);
		if (strcmp(nume, nume_o) == 0)
			return true;
	}
	return false;
}