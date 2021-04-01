#include "Vector.h"
#include <cstdlib>

template <class T>
Vector<T>::Vector()
{
	e = NULL;
	nr = 0;
}
template <class T>
Vector<T>::~Vector()
{
	if (e != NULL)
		free(e);
}
template <class T>
Vector<T>::Vector(const Vector& v)
{
	int i;
	if (v.e == NULL)
	{
		e = NULL;
		nr = 0;
	}
	else
	{
		e = (T*)malloc(sizeof(v.e));
		nr = v.nr;
		for (i = 0; i < nr; i++)
			e[i] = v.e[i];
	}
}
template <class T>
Vector<T>& Vector<T>::operator = (const Vector& v)
{
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
			e = (T*)malloc(sizeof(v.e));
			for (i = 0; i < nr; i++)
				e[i] = v.e[i];
		}
	}

	return *this;
}
template <class T>
void Vector<T>::push(T x)
{
	T* aux;
	int i;
	if (sizeof(e) / sizeof(T) > nr)
	{
		e[nr] = x;
		nr++;
	}
	else
	{
		aux = (T*)malloc(2 * sizeof(e));
		for (i = 0; i < nr; i++)
			aux[i] = e[i];
		aux[nr] = x;
		nr++;
		free(e);
		e = aux;
	}
}
template <class T>
T Vector<T>::pop()
{
	return e[nr - 1];
}
template <class T>
void Vector<T>::remove(int index)
{
	int i;
	if (index >= 0 && index <= nr - 1)
	{
		for (i = index + 1; i <= nr; i++)
			e[i - 1] = e[i];
		nr--;
	}
}
template <class T>
void Vector<T>::insert(T x, int index)
{
	int i;
	T* aux;
	if (index >= 0 && index <= nr)
	{
		if (sizeof(e) / sizeof(T) == nr)
		{
			aux = (T*)malloc(2 * sizeof(e));
			for (i = 0; i < nr; i++)
				aux[i] = e[i];
			free(e);
			e = aux;
		}
		for (i = nr - 1; i >= index; i--)
			e[i + 1] = e[i];
		e[index] = x;
	}
}
template <class T>
const T& Vector<T>::get(int index)
{
	return e[index];
}
template <class T>
void Vector<T>::set(int index, T x)
{
	if (index >= 0 && index <= nr - 1)
		e[index] = x;
}
template <class T>
int Vector<T>::count()
{
	return nr;
}
