#pragma once
template<class T>
class ArrayIterator
{
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
    T** Base;
public:
    void SetBase(T** base)
    {
        Base = base;
    }
    void SetCurrent(int current)
    {
        Current=current;
    }
    ArrayIterator()
    {
        Base = NULL;
        Current = 0;
    }
    ArrayIterator& operator ++ ()
    {
        Current++;
        return *this;
    }
    ArrayIterator& operator -- ()
    {
        Current--;
        return *this;
    }
    bool operator == (const ArrayIterator& a)
    {
        if (Base == a.Base && Current == a.Current)
            return true;
        else
            return false;
    }
    bool operator !=(const ArrayIterator& a)
    {
        if (Base!= a.Base || Current != a.Current)
            return true;
        else
            return false;
    }
    T* GetElement()
    {
        return *(Base + Current);
    }
};

