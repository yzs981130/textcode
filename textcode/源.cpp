#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <exception>
using namespace std;
class CArray
{
    size_t size;
    int *ptr;
public:
    CArray(int s = 0) {}
    CArray(const CArray &a);
    ~CArray();
    void push_back(int v);
    int length() { return size; }
    int &operator [](int i)
    {
        if (i > size || i < 0)
            throw runtime_error("out of range!");
        else
            return ptr[i];
    }
    CArray &operator = (const CArray & a);
};
int main()
{
    
    system("pause");
    return 0;
}

CArray::CArray(const CArray & a)
{
    if (!a.ptr)
    {
        ptr = nullptr;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}

CArray::~CArray()
{
    if (ptr)
        delete ptr;
}

void CArray::push_back(int v)
{
    if (ptr)
    {
        int *tmpptr = new int[size + 1];
        memcpy(tmpptr, ptr, sizeof(int) * size);
        delete[]ptr;
        ptr = tmpptr;
    }
    else
        ptr = new int[1];
    ptr[size++] = v;
}

CArray & CArray::operator=(const CArray & a)
{
    if (ptr == a.ptr)
        return *this;
    if (a.ptr == nullptr)
    {
        if (ptr)
            delete ptr;
        ptr = nullptr;
        size = 0;
        return *this;
    }
    if (size < a.size)
    {
        if (ptr)
            delete[]ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}
