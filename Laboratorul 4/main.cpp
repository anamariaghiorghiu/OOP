#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	int v[10] = { 9,10,4,6,8,1,2,3,5,7 };
	char s[100] = "4,7,12,33,5";
	Sort l1(10, 10, 100), l2, l3(5, 6,3,15, 20, 8), l4(v, 10), l5(s);
	cout << "List 1 before insert sort:" << endl;
	l1.Print();
	l1.InsertSort(true);
	cout << "\nList 1 after insert sort:" << endl;
	l1.Print();
	cout << endl;
	cout << "List 2 before bubble sort:" << endl;
	l2.Print();
	l2.BubbleSort();
	cout << "\nList 2 after bubble sort:" << endl;
	l2.Print();
	cout << endl;
	cout << "List 3 before quick sort:" << endl;
	l3.Print();
	l3.QuickSort();
	cout << "\nList 3 after quick sort:" << endl;
	l3.Print();
	cout << endl;
	cout << "List 4:" << endl;
	l4.Print();
	cout << "\nThe element from index 5 is:" << l4.GetElementFromIndex(5);
	cout << endl;
	cout << "List 5:" << endl;
	l5.Print();
	cout << "\nNumber of elements:" << l5.GetElementsCount();
	return 0;
}