#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
	Canvas c(20,20);
	int nr_op, i;
	int x, y, ray, left, top, right, bottom, x1,x2,y1,y2;
	char ch;
	do
	{
		cout << "1.Draw Circle		4.Fill Rect		0. Exit" << endl;
		cout << "2.Fill Circle		5.Set Point" << endl;
		cout << "3.Draw Rect		6.Draw Line" << endl;
		cout << "Choose an option!" << endl;
		cout << endl;
		cin >> nr_op;
		switch (nr_op)
		{
		case 1:
			cout << "Please give the coordinates of the circle:" << endl;
			cin >> x >> y;
			cout << "Please give the ray of the circle:" << endl;
			cin >> ray;
			cout << "Please give the character used for the outline:" << endl;
			cin >> ch;
			c.DrawCircle(x, y, ray, ch);
			c.Print();
			cout << endl;
			break;
		case 2:
			cout << "Please give the coordinates of the circle:" << endl;
			cin >> x >> y;
			cout << "Please give the ray of the circle:" << endl;
			cin >> ray;
			cout << "Please give the character used for the inside:" << endl;
			cin >> ch;
			c.FillCircle(x, y, ray, ch);
			c.Print();
			cout << endl;
			break;
		case 3:
			cout << "Please give the coordinate for the left:" << endl;
			cin >> left;
			cout << "Please give the coordinate for the top:" << endl;
			cin >> top;
			cout << "Please give the coordinate for the right:" << endl;
			cin >> right;
			cout << "Please give the coordinate for the bottom:" << endl;
			cin >> bottom;
			cout << "Please give the character used for the outline:" << endl;
			cin >> ch;
			c.DrawRect(left, top, right, bottom, ch);
			c.Print();
			cout << endl;
		case 4:
			cout << "Please give the coordinate for the left:" << endl;
			cin >> left;
			cout << "Please give the coordinate for the top:" << endl;
			cin >> top;
			cout << "Please give the coordinate for the right:" << endl;
			cin >> right;
			cout << "Please give the coordinate for the bottom:" << endl;
			cin >> bottom;
			cout << "Please give the character used for the inside:" << endl;
			cin >> ch;
			c.FillRect(left, top, right, bottom, ch);
			c.Print();
			cout << endl;
		case 5:
			cout << "Please give the coordinates of the point:" << endl;
			cin >> x >> y;
			cout << "Please give the character used for the point:" << endl;
			cin >> ch;
			c.SetPoint(x, y, ch);
			c.Print();
			cout << endl;
		case 6:
			cout << "Please give the first set of coordinates:" << endl;
			cin >> x1 >> y1;
			cout << "Please give the second set of coordinates:" << endl;
			cin >> x2 >> y2;
			cout << "Please give the character used for the line:" << endl;
			cin >> ch;
			c.DrawLine(x1, y1, x2, y2, ch);
			c.Print();
			cout << endl;
		default:
			if (nr_op != 0)
				cout << "The option does not exist!";
		}
		cout << endl;
	} while (nr_op != 0);
	return 0;
}

