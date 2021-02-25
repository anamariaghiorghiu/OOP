#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
    NumberList L;
    int nr_op, v;
    L.Init();
    do
    {
        cout << "1.Init" << endl;
        cout << "2.Add" << endl;
        cout << "3.Sort" << endl;
        cout << "4.Print" << endl;
        cout << "0.Exit" << endl;
        cout << "Choose your option:";
        
        cin >> nr_op;

        cout << endl;

        switch (nr_op)
        {
        case 1:
            L.Init();
            break;
        case 2:
            cout << "Value:";
            cin >> v;
            L.Add(v);
            break;
        case 3:
            L.Sort();
            cout << endl;
        case 4:
            L.Print();
            cout << endl;
            break;
        default:
            if (nr_op != 0)
                cout << "Non existent option!";
        }
        cout << endl;
    } while (nr_op != 0);
    return 0;
}
