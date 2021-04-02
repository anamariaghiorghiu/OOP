#pragma once
#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;


template <class T>
class Vector
{
private:
	T* e;
	int nr;
public:
	Vector() {
		e = NULL;
		nr = 0;
	}
	~Vector() {
		if (e != NULL)
			free(e);
	}
	Vector(const Vector& v) {
		int i;
		if (v.e == NULL)
		{
			e = NULL;
			nr = 0;
		}
		else
		{
			e = (T*)malloc(sizeof(*v.e));
			nr = v.nr;
			for (i = 0; i < nr; i++)
				e[i] = v.e[i];
		}
	}
	Vector& operator = (const Vector& v) {
		int i;
		if (this != &v)
		{
			if (e != NULL)
				free(e);
			nr = v.nr;
			if (v.e == NULL)
				e = NULL;
			else
			{
				e = (T*)malloc(sizeof(*v.e));
				for (i = 0; i < nr; i++)
					e[i] = v.e[i];
			}
		}

		return *this;
	}
	void push(T x) {
		T* aux;
		int i;
		if (e == NULL)
		{
			e = (T*)malloc(sizeof(T));
			e[0] = x;
			nr = 1;
		}
		else
			if (sizeof(*e) / sizeof(T) > nr)
			{
				e[nr] = x;
				nr++;
			}
			else
			{
				aux = (T*)malloc(2 * sizeof(*e));
				for (i = 0; i < nr; i++)
					aux[i] = e[i];
				aux[nr] = x;
				nr++;
				free(e);
				e = aux;
			}
	}
	T pop() {
		return e[nr - 1];
	}
	void remove(int index) {
		int i;
		if (index >= 0 && index <= nr - 1)
		{
			for (i = index + 1; i <= nr; i++)
				e[i - 1] = e[i];
			nr--;
		}
	}
	void insert(T x, int index)
	{
		int i;
		T* aux;
		if (index >= 0 && index <= nr)
		{
			if (e == NULL)
				e = (T*)malloc(sizeof(T));
			else
				if (sizeof(*e) / sizeof(T) == nr)
				{
					aux = (T*)malloc(2 * sizeof(*e));
					for (i = 0; i < nr; i++)
						aux[i] = e[i];
					free(e);
					e = aux;
				}
			for (i = nr - 1; i >= index; i--)
				e[i + 1] = e[i];
			e[index] = x;
			nr++;
		}
	}
	void sort(bool (*mai_mic)(T, T))
	{
		bool ordonat;
		T aux;
		int i;
		do
		{
			ordonat = true;
			for (i = 0; i < nr - 1; i++)
				if (mai_mic == NULL)
				{
					if (e[i + 1] < e[i])
					{
						ordonat = false;
						aux = e[i];
						e[i] = e[i + 1];
						e[i + 1] = aux;
					}
				}
				else
					if (mai_mic(e[i + 1], e[i]))
					{
						ordonat = false;
						aux = e[i];
						e[i] = e[i + 1];
						e[i + 1] = aux;
					}
		} while (!ordonat);
	}
	const T& get(int index)
	{
		return e[index];
	}
	void set(int index, T x)
	{
		if (index >= 0 && index <= nr - 1)
			e[index] = x;
	}
	int count() {
		return nr;
	}
	void Print()
	{
		int i;
		cout << "[";
		for (i = 0; i < nr; i++)
			cout << e[i] << ",";
		if (nr > 0)
			cout << "\b";
		cout << "]";
	}
	int firstIndexOf(T x, bool (*egal)(T, T))
	{
		int i;
		for (i = 0; i < nr; i++)
			if (egal == NULL)
			{
				if (e[i] == x)
					return i;
			}
			else
				if (egal(e[i], x))
					return i;
		return -1;
	}
};

