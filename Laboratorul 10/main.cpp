#include <iostream>
#include <exception>
#include "ArrayIterator.h"
#include "Array.h"
#include "Compare.h"

using namespace std;

int main()
{
    Array<int> a,aux;
    ArrayIterator<int> i;
    IntComparator comparator;
    int nro,element,index,size;
    do
    {
        cout << "1.Append element  6.Insert element       12.Sort using operator " << endl;
        cout << "2.Delete element  7.Insert array         13.Sort using function"<< endl;
        cout << "3.Show element    8.Show array           14.Sort using object"<< endl;
        cout << "4.Get size        9.Find using operator  15.Binary search using operator" << endl;
        cout << "5.Get capacity    10.Find using function 16.Binary search using function" << endl;
        cout << "0.Exit            11.Find using object   17.Binary search using object" << endl;
        cout << "Number of desired option:";
        cin >> nro;
        cout << endl;
        switch (nro)
        {
        case 1:
            cout << "element:";
            cin >> element;
            a += element;
            break;
        case 2:
            cout << "Index:";
            cin >> index;
            try { a.Delete(index); }
            catch (exception& e) { cout << e.what()<<endl; }
            break;
        case 3:
            cout << "Index:";
            cin >> index;
            try { cout << a[index]<<endl; }
            catch (exception& e) { cout << e.what()<<endl; }
            break;
        case 4:
            cout << "Array size:"<<a.GetSize()<<endl;
            break;
        case 5:
            cout << "Array capacity:"<<a.GetCapacity()<< endl;
            break;
        case 6:
            cout << "Element:";
            cin >> element;
            cout << "Index:";
            cin >> index;
            try { a.Insert(index, element); }
            catch (exception& e) { cout << e.what()<<endl; }
            break;
        case 7:
            aux.Clear();
            cout << "Array to be inserted" << endl;
            cout << "Number of elements:";
            cin >> size;
            cout << "Elements:";
            for (index = 1; index <= size; index++)
            {
                cin >> element;
                aux += element;
            }
            cout << "Position of insertion:";
            cin >> index;
            try { a.Insert(index, aux); }
            catch (exception& e) { cout << e.what()<<endl; }
            break;
        case 8:
            if (a.GetSize() == 0)
                cout << "empty array";
            else
                for (i = a.GetBeginIterator(); i != a.GetEndIterator(); ++i)
                    cout << *(i.GetElement())<<" ";
            cout << endl;
            break;
        case 9:
            cout << "Element:";
            cin >> element;
            if (a.Find(element)!=-1)
                cout << "Element was found!";
            else
                cout << "Element was NOT found!";
            cout << endl;
            break;
        case 10:
            cout << "Element:";
            cin >> element;
            if (a.Find(element,intCompare)!=-1)
                cout << "Element was found!";
            else
                cout << "Element was NOT found!";
            cout << endl;
            break;
        case 11:
            cout << "Element:";
            cin >> element;
            if (a.Find(element,&comparator)!=-1)
                cout << "Element was found!";
            else
                cout << "Element was NOT found!";
            cout << endl;
            break;
        case 12:
            a.Sort();
            break;
        case 13:
            a.Sort(intCompare);
            break;
        case 14:
            a.Sort(&comparator);
            break;
        case 15:
            if (a.Sorted())
            {
                cout << "Element:";
                cin >> element;
                if (a.BinarySearch(element) != -1)
                    cout << "Element was found!";
                else
                    cout << "Element was NOT found!";
                cout << endl;
            }
            else
                cout << "Array is not sorted. Binary search cannot be used!" << endl;
            break;
        case 16:
            if (a.Sorted(intCompare))
            {
                cout << "Element:";
                cin >> element;
                if (a.Find(element, intCompare) != -1)
                    cout << "Element was found!";
                else
                    cout << "Element was NOT found!";
                cout << endl;
            }
            else
                cout << "Array is not sorted. Binary search cannot be used!" << endl;
            break;
        case 17:
            if (a.Sorted(&comparator))
            {
                cout << "Element:";
                cin >> element;
                if (a.BinarySearch(element, &comparator) != -1)
                    cout << "Element was found!";
                else
                    cout << "Element was NOT found!";
                cout << endl;
            }
            else
                cout << "Array is not sorted. Binary search cannot be used!" << endl;
            break;
        default:
            if (nro != 0)
                cout << "Wrong option number !"<<endl;
        }
        cout << endl;
    }     
    while (nro != 0);
    return 0;
}