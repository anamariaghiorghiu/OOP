#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

Number::Number(const char* value, int base)
{
	this->numar = (char*)(malloc((strlen(value) + 1) * sizeof(char)));
	strcpy(this->numar, value);
	this->baza = base;
}

void Number::Print()
{
	printf("%s\n", this->numar);
}

int Valoare(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

char Valoare_char(int numar)
{
	if (numar >= 0 && numar <= 9)
		return (char)(numar + '0');
	else
		return (char)(numar - 10 + 'A');
}

void Invers_String(char* string)
{
	char aux;

	for (int i = 0; i < strlen(string) / 2; i++)
	{
		aux = string[i];
		string[i] = string[strlen(string) - i - 1];
		string[strlen(string) - i - 1] = aux;
	}
}

int TransformBase10(char* string, int base)
{
	int putere = 1;
	int rezultat = 0;

	for (int i = strlen(string) - 1; i >= 0; i--)
	{
		if (Valoare(string[i]) >= base)
		{
			printf("Eroare");
			return -1;
		}
		rezultat = rezultat + Valoare(string[i]) * putere;
		putere = putere * base;
	}

	return rezultat;
}

/*
void Number::SwitchBase(int newBase)
{
	char s[256];
	int nr;
	strcpy(s, this->numar);
	nr = TransformBase10(s, this->baza);
	strcpy(s, );
}*/