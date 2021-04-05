#define _CRT_SECURE_NO_WARNINGS
#include "Operatie.h"
#include <cstring>

void Operatie::getNume(char* nume)
{
	strcpy(nume, this->nume);
}