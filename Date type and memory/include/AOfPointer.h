//本类包含两个功能，获取二维数组的每一个存储单元的地址。以及再拥有二维每一存储单元的地址时，获取二维数组的首地址

#ifndef AOFPOINTER_H
#define AOFPOINTER_H

class AOfPointer
{
    public:
        AOfPointer();
        int** getPointer(int p[][5], int x, int y);//返回一个指针的指针（指针型数组），用于保存指针。用于存储二维数组每一存储单元的地址。
        int* mulArrayToLinearArray(int**);

};
AOfPointer::AOfPointer()
{

}
int** AOfPointer::getPointer(int p[][5], int x, int y)//
{
    int* *pOfArray = new int*[x * y];
    int a = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
             pOfArray[a] = &p[i][j];
             a++;
        }

    }
    return pOfArray;
}
int* AOfPointer::mulArrayToLinearArray(int** p)//获取一个指针的指针（指针型数组）的首地址。
{
    return *p;
}
#endif // AOFPOINTER_H
