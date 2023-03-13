#include <iostream>
#include "sortare.h"

using namespace std;

int main()
{
	Vector<int> v,v2;
	int x;
	cout << "Scrieti elementul pentru inserat in vector:" << endl;
	cin >> x;
	v.InsertElement(x, 0);
	v2.ReadVector();
	v.InsertVector(v2, 1);
	cout << "Vectorul:" << endl;
	v.PrintVector();
	cout << "\nVectorul sortat in ordine descrescatoare:" << endl;
	v.BubbleSort_descrescator();
	v.PrintVector();
	cout << "\nVectorul sortat in ordine crescatoare:" << endl;
	v.BubbleSort_crescator();
	v.PrintVector();
	return 0;
}