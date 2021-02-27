#pragma once
class Student
{
	char name[50];
	float math, history, english;
public:
	void SetName(char[]);
	void GetName(char[]);
	void SetMath(float);
	float GetMath();
	void SetHistory(float);
	float GetHistory();
	void SetEnglish(float);
	float GetEnglish();
	float Average();
};