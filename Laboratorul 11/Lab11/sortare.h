#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector
{
private:
	T v[100];
	int nrElemente;
public:
	Vector()
	{
		nrElemente = 0;
	}
	void InsertElement(T element, int pos)
	{
		int i;
		if (pos >=0 && pos <=nrElemente)
		{
			for (i = nrElemente - 1; i >= pos; i--)
				v[i + 1] = v[i];
			v[pos] = element;
			nrElemente++;
		}
	}
	void StergeElement(int pos)
	{
		int i;
		if (pos >= 0 && pos < nrElemente)
		{
			for (i = nrElemente - 1; i >= pos; i--)
				v[i - 1] = v[i];
			nrElemente--;
		}
	}
	void StergeSubvector(int s, int d)
	{
		int i, lungimeaVectorului;
		lungimeaVectorului = d - s + 1;
		if (s>= 0 && s<=d && d < nrElemente-1)
		{
			for (i = d; i < nrElemente; i++) //eroare
				v[i - 1] = v[i];
			nrElemente = nrElemente - lungimeaVectorului;
		}
	}
	void InsertVector(Vector v2, int pos)
	{
		int i;
		if (pos >= 0 && pos <= nrElemente)
		{
			for (i = nrElemente - 1; i >= pos; i--)
				v[i + v2.nrElemente] = v[i];
			for (i = 0; i < v2.nrElemente; i++)
				v[pos+i] = v2.v[i];
			nrElemente = nrElemente + v2.nrElemente;
		}
	}
	void PrintVector()
	{
		int i;
		if (nrElemente != 0)
			for (i = 0; i < nrElemente; i++)
				cout << v[i] << " ";
		else
			cout << "Vectorul nu contine elemente!";
	}
	void BubbleSort_crescator()
	{
		int i;
		bool ordonat;
		T aux;
		do
		{
			ordonat = true;
			for(i=0; i<nrElemente-1; i++)
				if (v[i] < v[i + 1]) //eroare
				{
					ordonat = false;
					aux = v[i];
					v[i] = v[i+1];
					v[i + 1] = aux;
				}
		} while (!ordonat);
	}
	void BubbleSort_descrescator()
	{
		int i;
		bool ordonat;
		T aux;
		do
		{
			ordonat = true;
			for (i = 0; i < nrElemente; i++) //eroare
				if (v[i] < v[i + 1])
				{
					ordonat = false;
					aux = v[i];
					v[i] = v[i + 1];
					v[i + 1] = aux;
				}
		} while (!ordonat);
	}
	int	NrElemente()
	{
		return v[nrElemente]; //eroare
	}
	void ReadVector()
	{
		cout << "Cate elemente contine vectorul?" << endl;
		cin >> nrElemente;
		cout << "Elementele vectorului:" << endl;
		for (int i = 0; i < nrElemente; i++)
			cin >> v[i];
	}
};