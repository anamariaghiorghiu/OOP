#pragma once
template <class T>
class Vector
{
private:
	T* e;
	int nr;
public:
	Vector();
	~Vector();
	Vector(const Vector&);
	Vector& operator = (const Vector&);
	void push(T);
	T pop();
	void remove(int);
	void insert(T, int);
	//sort method(sort all elements in the vector ==> use a callback function to provide a way to compare two elements.If the callback function is not present(nullptr), operator< is used.)
	const T& get(int); 
	void set(int, T);
	int count();
	//firstIndexOf method(given an object and a callback function, find the first index of the element from the vector that is equal(according to the callback function) with the given parameter.If the callback function is nor present(nullptr), operator== is used.
};

