#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <iostream>

using namespace std;

Sort::Sort(int n, int min, int max)
{
	int i;
	if (n > 0)
	{
		p = (int*)malloc(n * sizeof(int));
		this->n = n;
		srand(time(NULL)); //initializez motorul de generare aleatorie (pe baza timpului curent)
		for (i = 0; i < n; i++)
			p[i] = min + rand() % (max - min + 1);
	}
	else
	{
		this->n = 0;
		p = NULL;
	}
}
Sort::Sort(int p[], int n)
{
	int i;
	if(n>0)
	{
		this->p = (int*)malloc(n * sizeof(int));
		this->n= n;
		for (i = 0; i < n; i++)
			this->p[i] = p[i];
	}
	else
	{
		this->n = 0;
		p = NULL;
	}
}
Sort::Sort(char*s)
{
	char* q, *cs;
	int i;
	//fac o copie a sirului s in cs
	cs = (char*)malloc((strlen(s) + 1) * sizeof(char));
	strcpy(cs, s);
	//parcurg sirul pentru a determina numarul de valori
	n = 0;
	q = strtok(cs, ",");
	while (q != NULL)
	{
		n++;
		q = strtok(NULL, ",");
	}
	//aloc memorie pentru n valori 
	p = (int*)malloc(n * sizeof(int));
	//parcurg din nou sirul pentru a determina si copia valorile
	strcpy(cs, s);
	q = strtok(cs, ",");
	i = 0;
	while (q != NULL)
	{
		p[i] = atoi(q);
		i++;
		q = strtok(NULL, ",");
	}
	free(cs);
}
Sort::Sort(int n, ...)
{
	va_list l;
	int i;
	if (n > 0)
	{
		this->n = n;
		p = (int*)malloc(n * sizeof(int));
		va_start(l, n);
		for (i = 0; i < n; i++)
			p[i] = va_arg(l, int);
		va_end(l);
	}
	else
	{
		this->n = 0;
		p = NULL;
	}
}
Sort::Sort() 
{
	n = 10;
	int i;
	p = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		p[i] = i;
}
void Sort::InsertSort(bool ascendent)
{
	int i,j,k;
	int aux;
	if (ascendent)
	{
		for (i = 1; i < n; i++)
		{
			j = 0;
			while (p[j] < p[i])
				j++;
			aux = p[i];
			for (k = i; k > j; k--)
				p[k] = p[k - 1];
			p[j] = aux;
		}
	}
	else
	{
		for (i = 1; i < n; i++)
		{
			j = 0;
			while (p[j] > p[i])
				j++;
			aux = p[i];
			for (k = i; k > j; k--)
				p[k] = p[k - 1];
			p[j] = aux;
		}
	}
}
void Sort::QuickSort(bool ascendent)
{
	if (ascendent)
		QuickSort_R_A(0, n - 1);
	else
		QuickSort_R_D(0, n - 1);
}
void Sort::QuickSort_R_A(int st, int dr)
{
	int i, j;
	int aux;
	if (st < dr)
	{
		i = st + 1;
		j = dr;
		while (i <= j)
		{
			if (p[i] <= p[st]) i++;
			if (p[j] >= p[st]) j--;
			if (p[i] > p[st] && p[j] < p[st] && i < j)
			{
				aux = p[i];
				p[i] = p[j];
				p[j] = aux;
				i++;
				j--;
			}
		}
		aux = p[st];
		p[st] = p[j];
		p[j] = aux;
		QuickSort_R_A(st, j - 1);
		QuickSort_R_A(j + 1, dr);
	}
}
void Sort::QuickSort_R_D(int st, int dr)
{
	int i, j;
	int aux;
	if (st < dr)
	{
		i = st + 1;
		j = dr;
		while (i <= j)
		{
			if (p[i] >= p[st]) i++;
			if (p[j] <= p[st]) j--;
			if (p[i] < p[st] && p[j] > p[st] && i < j)
			{
				aux = p[i];
				p[i] = p[j];
				p[j] = aux;
				i++;
				j--;
			}
		}
		aux = p[st];
		p[st] = p[j];
		p[j] = aux;
		QuickSort_R_D(st, j - 1);
		QuickSort_R_D(j + 1, dr);
	}
}
Sort::~Sort()
{
	if (p != NULL)
		free(p);
}
void Sort::BubbleSort(bool ascendent)
{
	int i;
	bool ordonat;
	int aux;
	if (ascendent)
	{
		do
		{
			ordonat = true;
			for(i=0; i<n-1; i++)
				if (p[i] > p[i + 1])
				{
					ordonat = false;
					aux = p[i];
					p[i] = p[i + 1];
					p[i + 1] = aux;
				}
		} while (!ordonat);
	}
	else
	{
		do
		{
			ordonat = true;
			for (i = 0; i < n - 1; i++)
				if (p[i] < p[i + 1])
				{
					ordonat = false;
					aux = p[i];
					p[i] = p[i + 1];
					p[i + 1] = aux;
				}
		} while (!ordonat);
	}
}
void Sort::Print()
{
	int i;
	for (i = 0; i < n; i++)
		cout << p[i] << " ";
}
int Sort::GetElementsCount()
{
	return n;
}
int Sort:: GetElementFromIndex(int index)
{
	return p[index];
}