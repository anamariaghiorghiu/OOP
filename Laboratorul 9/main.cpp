#include <cstdio>
#define MAX 100

template <class K, class V>
class tripleta
{
public:
    K key;
    V value;
    int index;
};

template <class K, class V>
class Iterator
{
public:
    tripleta<K, V> *p;
    Iterator& operator++()
    {
        p++;
        return *this;
    }
    bool operator != (Iterator& m)
    {
        return p != m.p;
    }
    tripleta<K, V> operator* ()
    {
        return *p;
    }
};

template <class K, class V>
class Map
{
private:
    tripleta<K, V> t[MAX];
    int nt;
public:
    Map()
    {
        nt = 0;
    }
    void Set(K key, V value)
    {
        int i;
        bool gasit;
        i = 0;
        gasit = false;
        while (!gasit && i < nt)
            if (t[i].key == key)
                gasit = true;
            else
                i++;
        if (gasit)
            t[i].value = value;
        else
        {
            t[i].key = key;
            t[i].value = value;
            t[i].index = i;
            nt++;
        }
    }
    bool Get(const K& key, V& value)
    {
        int i;
        for (i = 0; i < nt; i++)
            if (t[i].key == key)
            {
                value = t[i].value;
                return true;
            }
        return false;
    }
    int Count()
    {
        return nt;
    }
    void Clear()
    {
        nt = 0;
    }
    bool Delete(const K& key)
    {
        int i, j;
        for (i = 0; i < nt; i++)
            if (t[i].key == key)
            {
                for (j = i + 1; j < nt; j++)
                {
                    t[j].index--;
                    t[j - 1] = t[j];
                }
                nt--;
                return true;
            }
        return false;
    }
    bool Includes(const Map<K, V>& map)
    {
        int i;
        V value;
        for (i = 0; i < map.nt; i++)
            if (!Get(map.t[i].key, value))
                return false;
        return true;
    }
    V& operator [](K key)
    {
        int i;
        bool gasit;
        i = 0;
        gasit = false;
        while (!gasit && i < nt)
            if (t[i].key == key)
                gasit = true;
            else
                i++;
        if (!gasit)
        {
            t[i].key = key;
            t[i].index = i;
            nt++;
        }
        return t[i].value;
    }
    Iterator<K, V> begin()
    {
        Iterator<K, V> tmp;
        tmp.p = &t[0];
        return tmp;
    }
    Iterator<K, V> end()
    {
        Iterator<K, V> tmp;
        tmp.p = &t[nt];
        return tmp;
    }
};



int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}