//������ƽ����ע�⣬����������ǹ̶��ģ�����c++�Զ�ά����Ĵ������ԣ�����̶���ά�Լ�����ά�ķ�Χ�����ԡ���������������
#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H


class SquareMatrix
{
    public:
        SquareMatrix();
        int* getSquare(int towArray[][5]);
};
SquareMatrix::SquareMatrix()
{

}
int* SquareMatrix::getSquare(int towArray[][5])
{
    int *p = new int[25];
    for (int i = 0; i < 25; i++)
        p[i] = 0;
    int a = 0;
    for (int i = 0 ; i < 5; i++)//�����������
    {
        for (int j = 0; j < 5; j++)//�����������
        {
             for (int k = 0; k < 5; k++)
             {
                 p[i * 5 + j] += towArray[i][k] * towArray[k][j];
             }
             a++;
        }
    }
    return p;
}
#endif // SQUAREMATRIX_H
