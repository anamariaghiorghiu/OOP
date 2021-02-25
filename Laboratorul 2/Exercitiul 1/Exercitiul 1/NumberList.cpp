#include "NumberList.h"
#include <iostream>

void NumberList::Init()
{
	count = 0;
}
bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	else
	{
		numbers[count] = x;
		count++;
		return true;
	}
}
void NumberList::Sort()
{
	int i, aux;
	bool ordonat;
	do
	{
		ordonat = true;
		for (i = 1; i < count-1; i++)
			if (numbers[i] > numbers[i + 1])
			{
				aux = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = aux;
			}
	} while (!ordonat);

}
void NumberList::Print()
{
	int i;
	for (i = 0; i < count; i++)
		std::cout << numbers[i] << " ";
}