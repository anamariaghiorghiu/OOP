#define _CRT_SECURE_NO_WARNINGS
#include "GlobalFunctions.h"
#include <cstring>

int CompareNames(Student s1, Student s2)
{
	int r;
	char nume1[50], nume2[50];
	s1.GetName(nume1);
	s2.GetName(nume2);
	r = strcmp(nume1, nume2);
	if (r < 0)
		return -1;
	else if (r > 0)
		return 1;
	return r;
}
int CompareMath(Student s1, Student s2)
{
	if (s1.GetMath() < s2.GetMath())
		return -1;
	else if (s1.GetMath() > s2.GetMath())
		return 1;
	return 0;
}
int CompareHistory(Student s1, Student s2)
{
	if (s1.GetHistory() < s2.GetHistory())
		return -1;
	else if (s1.GetHistory() > s2.GetHistory())
		return 1;
	return 0;
}
int CompareEnglish(Student s1, Student s2)
{
	if (s1.GetEnglish() < s2.GetEnglish())
		return -1;
	else if (s1.GetEnglish() > s2.GetEnglish())
		return 1;
	return 0;
}
int CompareAverage(Student s1, Student s2)
{
	if (s1.Average() < s2.Average())
		return -1;
	else if (s1.Average() > s2.Average())
		return 1;
	return 0;
}
