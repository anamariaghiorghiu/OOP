#pragma once

class Sort
{
    double *p;
    int n;

public:
    Sort(int, double, double);
    Sort(double[], int);
    Sort(char*);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

private:
    void QuickSort_R_A(int, int);
    void QuickSort_R_D(int, int);
};

