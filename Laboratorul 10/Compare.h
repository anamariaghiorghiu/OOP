#pragma once
class Compare
{
public:
	virtual int CompareElements(const void* e1, const void* e2) = 0;
};

class IntComparator :public Compare
{
	int CompareElements(const void* e1,const void* e2)
	{
		if (*(int*)e1 < *(int*)e2)
			return -1;
		else
			if (*(int*)e1 == *(int*)e2)
				return 0;
			else
				return 1;
	}
};

int intCompare(const int& v1, const int& v2)
{
	if (v1 < v2)
		return -1;
	else
		if (v1 == v2)
			return 0;
		else
			return 1;
}