//将浮点数转位二进制输出，
//计算sign， E， M；
//通过浮点数的存储原理，计算出二进制。
#ifndef FTOBINARY_H
#define FTOBINARY_H
#include "math.h"

template <class T>
class FToBinary
{
public:
    FToBinary();
    int* fToB(T &t);//获取二维浮点数的二进制数。并存在一个int型数组
    void bTof(T &t);//通过使用浮点数的二进制数组计算出原来的值。
};
template <typename T>
FToBinary<T>::FToBinary()
{

}

template <typename T>
int* FToBinary<T>::fToB(T &t)
{
    int *fToBArray = new int[sizeof(T) * 8];
    if (sizeof(T) == sizeof(float))
    {
        union
        {
            float ff;
            int32_t intff;
        }myUnion;
        myUnion.ff = t;
        for ( int i = sizeof(T) * 8 - 1, j = 0; i >= 0; i--, j++ )
        {
            fToBArray[j] = (myUnion.intff >> i ) & 1;
        }
    }
    else if (sizeof(T) == sizeof(double))
    {
        union
        {
            double dd;
            int64_t intdd;
        }myUnion;
        myUnion.dd = t;
        for (int i = sizeof(T) * 8 - 1, j = 0; i >= 0; i--, j++ )
        {
            fToBArray[j] = (myUnion.intdd >> i ) & 1;//位运算，从高位开始
        }
    }
//以下，也是一种方法，对获取float的二进制没有问题，但对double则出现问题，问题尚未解决
//    int f = *(int*)&t;
//    int *fToBArray = new int[sizeof(T) * 8];
//    for (int i = 0; i < sizeof(T) * 8; i++)
//    {
        //cout << "sizeof: " << sizeof(T) * 8 << endl;
//        fToBArray[i] = ((1 << sizeof(T) * 8 - 1 - i) & f) != 0 ? 1 : 0;
//    }
    return fToBArray;
}

template <typename T>
void FToBinary<T>::bTof(T &t)
{
    int *p = fToB(t);
    int s = 0;
    int E = 0;
    double M = 0;
    s = p[0];//符号位
    if (sizeof(t) == sizeof(float))
    {
        int e1 = 0;
        double f = 0.0;
        int isNomal = 1;//1为正规化，0为非正规化，-1为特殊值，此处对特殊值不做其他处理
        int count1 = 0;
        for (int i = 1; i < 9; i++)
        {
            if (p[i] == 0)
                count1++;
            if(count1 == 8)
                isNomal = 0;
        }
        int count2;
        for (int i = 1; i < 9; i++)//对阶码域进行处理
        {
            if (p[i] == 1)
                count2++;
            if(count2 == 8)
                isNomal = -1;
        }
        for (int i = 8; i >= 1; i--)
        {
            if (p[i] == 1)
               e1 = e1 + pow(2, 8 - i);
        }
        for (int i = 9; i < sizeof(t) * 8; i++)//对尾数域进行处理
        {
            if (p[i] == 1)
                f = f + pow(2, 8 - i);
        }
        cout << "f: " << f << endl;
        if (isNomal == 0)
        {
            E = 1 - (pow(2, 7) - 1);
            M = f;
        }

        else
        {
             E = e1 - (pow(2, 7) - 1);
             M = 1.0 + f;
        }
    }
    else if (sizeof(t) == sizeof(double))
    {
        int e1 = 0;
        double f = 0.0;
        int isNomal = 1;
        int count1 = 0;
        for (int i = 1; i < 12; i++)
        {
            if (p[i] == 0)
                count1++;
            if(count1 == 11)
                isNomal = 0;
        }
        int count2;
        for (int i = 1; i < 12; i++)
        {
            if (p[i] == 1)
                count2++;
            if(count2 == 11)
                isNomal = -1;
        }
        for (int i = 11; i >= 1; i--)
        {
            if(p[i] == 1)
                e1 = e1 + pow(2, 11 - i);
        }
        for (int i = 12; i < sizeof(t) * 8; i++)
        {
            if (p[i] == 1)
                 f = f + pow(2, 11 - i);
        }
        cout << "f: " << f << endl;
        if (isNomal == 0)
        {
            E = 1 - (pow(2, 10) - 1);
            M = f;
        }

        else if (isNomal == 1)
        {
             E = e1 - (pow(2, 10) - 1);
             M = 1.0 + f;
        }
    }
    cout << "s: " << s << "  M: " << M << "   E: " << E <<endl;
    cout << "V: " << pow(-1, s) * M * pow(2, E);//计算浮点数
}

#endif // FTOBINARY_H
