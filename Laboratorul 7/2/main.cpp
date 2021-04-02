#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{
	Vector<int> v;
	int nr_o;
	int x;
	int index;
	do
	{
		cout << "1.Push		 5.Set			  9. Sort" << endl;
		cout << "2.Insert	 6.Get			  10.Print" << endl;
		cout << "3.Remove	 7.Count		  0.Exit" << endl;
		cout << "4.Pop		 8.FirstIndexOf" << endl;
		cout << "Number of desired option:";
		cin >> nr_o;
		cout << endl;
		switch (nr_o)
		{
		case 1:
			cout << "Value:";
			cin >> x;
			v.push(x);
			break;
		case 2:
			cout << "Value:";
			cin >> x;
			cout << "Position:";
			cin >> index;
			v.insert(x, index);
			break;
		case 3:
			cout << "Position:";
			cin >> index;
			v.remove(index);
			break;
		case 4:
			if (v.count() == 0)
				cout << "Vector is empty!" << endl;
			else
				cout << v.pop() << endl;
			break;
		case 5:
			cout << "Value:";
			cin >> x;
			cout << "Position:";
			cin >> index;
			v.set(index, x);
			break;
		case 6:
			cout << "Position:";
			cin >> index;
			if (index >= 0 && index < v.count())
				cout << v.get(index);
			else
				cout << "Position is incorrect!";
			cout << endl;
			break;
		case 7:
			cout << "Number of elements:" << v.count() << endl;
			break;
		case 8:
			cout << "Value:";
			cin >> x;
			index = v.firstIndexOf(x, NULL);
			if (index == -1)
				cout << "Value was not found!" << endl;
			else
				cout << "First index of " << x << " is " << index << endl;
			break;
		case 9:
			v.sort(NULL);
			break;
		case 10:
			v.Print();
			cout << endl;
			break;
		default:
			if (nr_o != 0)
				cout << "Option does not exist!" << endl;
		}
		cout << endl;
	} while (nr_o != 0);
	return 0;
}