#pragma once
#include "Compare.h"
#include "IndexException.h"
#include "ArrayIterator.h"

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:
	Array() // Lista nu e alocata, Capacity si Size = 0
	{
		List = NULL;
		Capacity = 0;
		Size = 0;
	}
	~Array() // destructor
	{
		Clear();
	}
	Array(int capacity) // Lista e alocata cu 'capacity' elemente
	{
		List = (T**)malloc(capacity * sizeof(T*));
		Capacity = capacity;
		Size = 0;
	}
	Array(const Array& otherArray) // constructor de copiere
	{
		int i;
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		if (otherArray.List == NULL)
			List = NULL;
		else
		{
			List= (T**)malloc(Capacity * sizeof(T*));
			for (i = 0; i < Size; i++)
			{
				List[i] = new T;
				*List[i] = *otherArray.List[i];
			}
		}
	}
	Array& operator=(const Array& otherArray) //supraincarcare operator de atribuire
	{
		int i;
		if (this != &otherArray)
		{
			Capacity = otherArray.Capacity;
			Size = otherArray.Size;
			if (List != NULL)
			{
				for (i = 0; i < Size; i++)
					free(List[i]);
				free(List);
			}
			List = (T**)malloc(Capacity * sizeof(T*));
			for (i=0;i<Size;i++)
			{
				List[i] = new T;
				*List[i] = *otherArray.List[i];
			}
		}
		return *this;
	}
	T& operator[] (int index) // arunca exceptie daca index este out of range
	{
		IndexException e;
		if (index < 0 || index > Size - 1)
			throw e;
		return *List[index];
	}
	const Array& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
	{
		int i;
		T** auxList;
		if (Size == Capacity)
		{
			auxList = (T**)malloc((Capacity + 1) * sizeof(T*));
			for (i = 0; i < Size; i++)
				auxList[i] = List[i];
			if (List != NULL)
				free(List);
			List = auxList;
			Capacity++;
		}
		List[Size] = new T;
		*List[Size] = newElem;
		Size++;
		return *this;
	}
	const Array& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		int i;
		T** auxList;
		IndexException e;
		if (index < 0 || index > Size)
			throw e;
		if (Size == Capacity)
		{
			auxList = (T**)malloc((Capacity + 1) * sizeof(T*));
			for (i = 0; i < Size; i++)
				auxList[i] = List[i];
			if (List!=NULL)
				free(List);
			List = auxList;
			Capacity++;
		}
		for (i = Size - 1; i >= index; i--)
			List[i+1] = List[i];
		List[index] = new T;
		*List[index] = newElem;
		Size++;
		return *this;
	}
	const Array& Insert(int index, const Array& otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		int i;
		T** auxList;
		IndexException e;
		if (index < 0 || index > Size)
			throw e;
		if (Size + otherArray.Size > Capacity)
		{
			auxList = (T**)malloc((Size + otherArray.Size) * sizeof(T*));
			for (i = 0; i < Size; i++)
				auxList[i] = List[i];
			if (List!=NULL)
				free(List);
			List = auxList;
			Capacity = Size + otherArray.Size;
		}
		for (i = Size - 1; i >= index; i--)
			List[i + otherArray.Size] = List[i];
		for (i = 0; i < otherArray.Size; i++)
		{
			List[index+i] = new T;
			*List[index + i] = *otherArray.List[i];
		}
		Size += otherArray.Size;
		return *this;
	}
	const Array& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	{
		int i;
		IndexException e;
		if (index < 0 || index > Size - 1)
			throw e;
		free(List[index]);
		for (i = index + 1; i <= Size - 1; i++)
			List[i - 1] = List[i];
		Size--;
		return *this;
	}
	bool operator==(const Array& otherArray)
	{
		int i;
		if (Size != otherArray.Size)
			return false;
		else
			for (i = 0; i < Size; i++)
				if (*List[i] != *otherArray.List[i])
					return false;
		return true;
	}
	void Sort()
	{
		int i;
		bool ordonat;
		T* aux;
		do
		{
			ordonat = true;
			for (i=0;i<Size-1;i++)
				if (*List[i] > *List[i + 1])
				{
					ordonat = false;
					aux = List[i];
					List[i] = List[i + 1];
					List[i + 1] = aux;
				}
		} 		
		while (!ordonat);
	}
	void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
	{
		int i;
		bool ordonat;
		T* aux;
		do
		{
			ordonat = true;
			for (i = 0; i < Size - 1; i++)
				if (compare(*List[i],*List[i + 1])>0)
				{
					ordonat = false;
					aux = List[i];
					List[i] = List[i + 1];
					List[i + 1] = aux;
				}
		} 		while (!ordonat);

	}
	void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
	{
		int i;
		bool ordonat;
		T* aux;
		do
		{
			ordonat = true;
			for (i = 0; i < Size - 1; i++)
				if (comparator->CompareElements(List[i], List[i + 1]) > 0)
				{
					ordonat = false;
					aux = List[i];
					List[i] = List[i + 1];
					List[i + 1] = aux;
				}
		}
 		while (!ordonat);
	}

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
	{
		int m,s,d;
		bool gasit;
		s = 0;
		d = Size - 1;
		gasit = false;
		while (!gasit && s <= d)
		{
			m = (s + d) / 2;
			if (*List[m] == elem)
				gasit = true;
			else
				if (*List[m] < elem)
					s = m + 1;
				else
					d = m - 1;
		}
		if (gasit)
			return m;
		else
			return -1;
	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
	{
		int m, s, d;
		bool gasit;
		s = 0;
		d = Size - 1;
		gasit = false;
		while (!gasit && s <= d)
		{
			m = (s + d) / 2;
			if (compare(*List[m], elem)==0)
				gasit = true;
			else
				if (compare(*List[m], elem)<0)
					s = m;
				else
					d = m - 1;
		}
		if (gasit)
			return m;
		else
			return -1;
	}
	int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
	{
		int m, s, d;
		bool gasit;
		s = 0;
		d = Size - 1;
		gasit = false;
		while (!gasit && s <= d)
		{
			m = (s + d) / 2;
			if (comparator->CompareElements(List[m] ,&elem)==0)
				gasit = true;
			else
				if (comparator->CompareElements(List[m], &elem)<0)
					s = m;
				else
					d = m - 1;
		}
		if (gasit)
			return m;
		else
			return -1;
	}

	int Find(const T& elem) // cauta un element in Array
	{
		int i;
		for (i = 0; i < Size; i++)
			if (*List[i] == elem)
				return i;
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
	{
		int i;
		for (i = 0; i < Size; i++)
			if (compare(*List[i], elem)==0)
				return i;
		return -1;
	}
	int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
	{
		int i;
		for (i = 0; i < Size; i++)
			if (comparator->CompareElements(List[i], &elem) == 0)
				return i;
		return -1;
	}
	int GetSize()
	{
		return Size;
	}
	int GetCapacity()
	{
		return Capacity;
	}
	ArrayIterator<T> GetBeginIterator()
	{
		ArrayIterator<T> i;
		i.SetBase(List);
		i.SetCurrent(0);
		return i;
	}
	ArrayIterator<T> GetEndIterator()
	{
		ArrayIterator<T> i;
		i.SetBase(List);
		i.SetCurrent(Size);
		return i;
	}
	void Clear()
	{
		int i;
		if (List != NULL)
		{
			for (i = 0; i < Size; i++)
				free(List[i]);
			free(List);
		}
		List = NULL;
		Size = 0;
		Capacity = 0;
	}
	bool Sorted()
	{
		int i;
		for (i = 0; i < Size-1; i++)
			if (*List[i] > *List[i + 1])
				return false;
		return true;
	}
	bool Sorted(int(*compare)(const T&, const T&))
	{
		int i;
		for (i = 0; i < Size - 1; i++)
			if (compare(*List[i],*List[i + 1])>0)
				return false;
		return true;
	}
	bool Sorted(Compare* comparator)
	{
		int i;
		for (i = 0; i < Size - 1; i++)
			if (comparator->CompareElements(List[i],List[i + 1])>0)
				return false;
		return true;
	}
};