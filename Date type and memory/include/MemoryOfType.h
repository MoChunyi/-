//����������͵�ÿһ�ֽڵĵ�ַ���Լ��õ�ַ�������ֵ
#ifndef MEMORYOFTYPE_H
#define MEMORYOFTYPE_H
#include <iostream>
#include <stdio.h>
using namespace std;

template <class T>

class MemoryOfType
{
    public:
        MemoryOfType();
        void getMemory(T &t);
};
template<typename T>
MemoryOfType<T>::MemoryOfType()
{

}
template<typename T>
void MemoryOfType<T>::getMemory(T &t)
{
    typedef unsigned char *byte_pointer;
    byte_pointer start = (byte_pointer) &t;
    for (size_t i = 0; i < sizeof(t); i++)
    {
        printf("%.2x, %p\n", start[i], &start[i]);
    }
}

#endif // MEMORYOFTYPE_H
