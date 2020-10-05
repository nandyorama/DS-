#include <bits/stdc++.h>
using namespace std;
#define M 4

//Using DFS
bool detectCycleUsingParentUtil(vector<int> edge[M],vector<bool> &visited,vector<int> &rec,int i)
{
    visited[i] = true;
    for(int j =0;j<edge[i].size();j++)
    {
        if(!visited[edge[i][j]])
        {
            rec[edge[i][j]] = i;
            detectCycleUsingParentUtil(edge,visited,rec,edge[i][j]);
        }
        else if(rec[i] != edge[i][j])
        {
            return true;
        }
    }
    return false;
}
int detectCycleUsingParent(vector<int> edge[M],int n)
{
    vector<bool> visited(n,false);
    vector<int> rec(n,-1);
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && detectCycleUsingParentUtil(edge,visited,rec,i))
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    //Undirected Graph    
    vector<int> edge[M];
    edge[0].push_back(1);
    edge[1].push_back(0);

    edge[0].push_back(2);
    edge[2].push_back(0);

    edge[1].push_back(2);
    edge[2].push_back(1);

    edge[2].push_back(3);
    edge[3].push_back(2);
    if(detectCycleUsingParent(edge,5))
        cout<<"YES CYCLE"<<endl;
    else
        cout<<"NO CYCLE"<<endl;
    
    return 0;    
 }
