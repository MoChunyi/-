//求矩阵的平方。注意，传入的数组是固定的，由于c++对二维数组的传参特性，必须固定二维以及更高维的范围，所以。。。。。。。。
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
    for (int i = 0 ; i < 5; i++)//所求数组的行
    {
        for (int j = 0; j < 5; j++)//所求数组的列
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
