//��������������ܣ���ȡ��ά�����ÿһ���洢��Ԫ�ĵ�ַ���Լ���ӵ�ж�άÿһ�洢��Ԫ�ĵ�ַʱ����ȡ��ά������׵�ַ

#ifndef AOFPOINTER_H
#define AOFPOINTER_H

class AOfPointer
{
    public:
        AOfPointer();
        int** getPointer(int p[][5], int x, int y);//����һ��ָ���ָ�루ָ�������飩�����ڱ���ָ�롣���ڴ洢��ά����ÿһ�洢��Ԫ�ĵ�ַ��
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
int* AOfPointer::mulArrayToLinearArray(int** p)//��ȡһ��ָ���ָ�루ָ�������飩���׵�ַ��
{
    return *p;
}
#endif // AOFPOINTER_H
