#pragma once

class Sort
{
    int *p;
    int n;

public:
    Sort(int, int, int);
    Sort(int[], int);
    Sort(char*);
    Sort(int,...);
    Sort();
    ~Sort();
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

