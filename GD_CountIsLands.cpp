#include <bits/stdc++.h>
using namespace std;
#define M 5

bool check(int x, int y, bool visited[M][M], int mat[M][M])
{
    if(x<M && x>=0 && y<M && y>=0 && !visited[x][y] && mat[x][y])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs(bool visited[M][M], int mat[M][M], int i,int j)
{
    if(i==M-1 && j == M-1)
        return;
        
    visited[i][j] = 1;
    // For 8 Direction - Output - 5  
    // int x[]={-1,0,1,0,1,-1,-1,1};
    // int y[]={0,-1,0,1,1,-1,1,-1};
    
    // For 4 Direction - Output - 6
    int x[]={-1,0,1,0};
    int y[]={0,-1,0,1};
    int sz = sizeof(x)/sizeof(x[0]);
    for(int index=0;index<sz;index++)
    {
        if(check(i+x[index],j+y[index],visited,mat))
        {
            dfs(visited,mat,i+x[index],j+y[index]);
        }
    }
}

int countNumberIsland(int mat[M][M])
{
    bool visited[M][M];
    int count = 0;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<M;j++)
        {
            visited[i][j] = 0;
        }
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(!visited[i][j] && mat[i][j])
            {
                dfs(visited,mat,i,j);
                count++;
            }
        }
    }
    return count;
}

int main()
{
   int mat[M][M] ={{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}}; 
   cout<<countNumberIsland(mat);               
   return 0;
}
