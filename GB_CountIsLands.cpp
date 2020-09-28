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

using node = struct{
    int x;int y;
};

void bfs(bool visited[M][M], int mat[M][M], int i,int j)
{
    list<node> Q;
    node n = {i,j};
    Q.push_back(n);
    while(!Q.empty())
    {
        node temp = Q.front();
        Q.pop_front();
        visited[temp.x][temp.y] = 1;
        
        //For Only 4-Directions        
        int x[]={-1,0,1,0};
        int y[]={0,-1,0,1};
        int sz = sizeof(x)/sizeof(x[0]);
        for(int index=0;index<sz;index++)
        {
            if(check(temp.x+x[index],temp.y+y[index],visited,mat))
            {
                Q.push_back({temp.x+x[index], temp.y+y[index]});
            }
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
                bfs(visited,mat,i,j);
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
