#include <bits/stdc++.h>
using namespace std;
#define N 4

//Using DFS
bool detectCycleUtil(vector<int> edge[N],vector<bool> visited,vector<bool> rec,int i)
{
    visited[i] = true;
    rec[i] = true;
    for(int j =0;j<edge[i].size();j++)
    {
        if(!visited[edge[i][j]] && detectCycleUtil(edge,visited,rec,edge[i][j]))
            return true;
        else if(rec[edge[i][j]])
            return true;
    }
    rec[i] = false;
    return false;
}

int detectCycle(vector<int> edge[N])
{
    vector<bool> visited(N,false);
    vector<bool> rec(N,false);
    for(int i=0;i<N;i++)
    {
        if(!visited[i] && detectCycleUtil(edge,visited,rec,i))
        {
            return 1;
        }
    }
    return 0;
}
 
int main()
{
    vector<int> edge[N];
    edge[0].push_back(1);
    edge[0].push_back(2);
    edge[1].push_back(2);
    edge[2].push_back(0);//NO Cycle
    edge[2].push_back(3);
    if(detectCycle(edge))
        cout<<"YES CYCLE"<<endl;
    else
        cout<<"NO CYCLE"<<endl;
        
    return 0;
 }
