//��������תλ�����������
//����sign�� E�� M��
//ͨ���������Ĵ洢ԭ������������ơ�
#ifndef FTOBINARY_H
#define FTOBINARY_H
#include "math.h"

template <class T>
class FToBinary
{
public:
    FToBinary();
    int* fToB(T &t);//��ȡ��ά�������Ķ���������������һ��int������
    void bTof(T &t);//ͨ��ʹ�ø������Ķ�������������ԭ����ֵ��
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
            fToBArray[j] = (myUnion.intdd >> i ) & 1;//λ���㣬�Ӹ�λ��ʼ
        }
    }
//���£�Ҳ��һ�ַ������Ի�ȡfloat�Ķ�����û�����⣬����double��������⣬������δ���
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
    s = p[0];//����λ
    if (sizeof(t) == sizeof(float))
    {
        int e1 = 0;
        double f = 0.0;
        int isNomal = 1;//1Ϊ���滯��0Ϊ�����滯��-1Ϊ����ֵ���˴�������ֵ������������
        int count1 = 0;
        for (int i = 1; i < 9; i++)
        {
            if (p[i] == 0)
                count1++;
            if(count1 == 8)
                isNomal = 0;
        }
        int count2;
        for (int i = 1; i < 9; i++)//�Խ�������д���
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
        for (int i = 9; i < sizeof(t) * 8; i++)//��β������д���
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
    cout << "V: " << pow(-1, s) * M * pow(2, E);//���㸡����
}

#endif // FTOBINARY_H
