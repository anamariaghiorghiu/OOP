#pragma once

class Operatie
{
protected:
	const char* nume;
public:
	virtual void calculeaza(double, double)=0;
	void getNume(char*);
};