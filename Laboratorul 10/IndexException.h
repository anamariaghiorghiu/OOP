#pragma once
#include <exception>

using namespace std;

class IndexException : public exception
{
	virtual const char* what() const throw()
	{
		return "Invalid index!";
	}
};

