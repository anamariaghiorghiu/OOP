#include <iostream>
#include "Student.h"
#include "GlobalFunctions.h"
#include <limits>
using namespace std;

int main()
{
    Student s1, s2;
    char name[50];
    float math, history, english;
    int r;
    cout << "Please introduce the data for the first student!" << endl;
    cout << "Name:";
    cin.getline(name, 50);
    cout << "Math grade:";
    cin >> math;
    cout << "History grade:";
    cin >> history;
    cout << "English grade:";
    cin >> english;
    s1.SetName(name);
    s1.SetMath(math);
    s1.SetHistory(history);
    s1.SetEnglish(english);
    cout << "Please introduce the data for the second student!" << endl;
    cout << "Name:";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(name, 50);
    cout << "Math grade:";
    cin >> math;
    cout << "History grade:";
    cin >> history;
    cout << "English grade:";
    cin >> english;
    s2.SetName(name);
    s2.SetMath(math);
    s2.SetHistory(history);
    s2.SetEnglish(english);
    cout << "Comparison by name:";
    r = CompareNames(s1, s2);
    if (r == -1)
        cout << "Student one < Student two" << endl;
    else
        if (r == 0)
            cout << "Student one = Student two" << endl;
        else
            cout << "Student one > Student two" << endl;
    cout << "Comparison by math grade:";
    r = CompareMath(s1, s2);
    if (r == -1)
        cout << "Student one < Student two" << endl;
    else
        if (r == 0)
            cout << "Student one = Student two" << endl;
        else
            cout << "Student one > Student two" << endl;
    cout << "Comparison by history grade:";
    r = CompareHistory(s1, s2);
    if (r == -1)
        cout << "Student one < Student two" << endl;
    else
        if (r == 0)
            cout << "Student one = Student two" << endl;
        else
            cout << "Student one > Student two" << endl;
    cout << "Comparison by english grade:";
    r = CompareEnglish(s1, s2);
    if (r == -1)
        cout << "Student one < Student two" << endl;
    else
        if (r == 0)
            cout << "Student one = Student two" << endl;
        else
            cout << "Student one > Student two" << endl;
    cout << "Comparison by average:";
    r = CompareAverage(s1, s2);
    if (r == -1)
        cout << "Student one < Student two" << endl;
    else
        if (r == 0)
            cout << "Student one = Student two" << endl;
        else
            cout << "Student one > Student two" << endl;
    return 0;
}
