#include<bits/stdc++.h>
using namespace std;
#define N 4
void rotateMatrix(int mat[N][N])
{
    for(int x =0;x <N/2;x++)
    {
        for(int y =x;y <N-x-1;y++)
        {
            int temp = mat[x][y];
            mat[x][y] = mat[y][N-x-1];
            mat[y][N-x-1] = mat[N-x-1][N-y-1];
            mat[N-x-1][N-y-1] = mat[N-y-1][x];
            mat[N-y-1][x] = temp;
        }
    }
}
void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);
 
        printf("\n");
    }
    printf("\n");
}
 
 
int main()
{
    int mat[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateMatrix(mat);
    displayMatrix(mat);
 
    return 0;
}
