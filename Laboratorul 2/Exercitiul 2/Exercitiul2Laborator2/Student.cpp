#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>

void Student::SetName(char name[])
{
	strcpy(this->name, name);
}
void Student::GetName(char name[])
{
	strcpy(name, this->name);
}
void Student::SetMath(float math)
{
	this->math = math;
}
float Student::GetMath()
{
	return math;
}
void Student::SetHistory(float history)
{
	this->history = history;
}
float Student::GetHistory()
{
	return history;
}
void Student::SetEnglish(float english)
{
	this->english = english;
}
float Student::GetEnglish()
{
	return english;
}
float Student::Average()
{
	return (math + history + english) / 3;
}