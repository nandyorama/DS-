#include <bits/stdc++.h>
using namespace std;
//Using BFS
void printLevel(vector<int> g[], int n,int index)
{
    int level[n];
    list<int> Q;
    Q.push_back(index);
    bool visited[n]={false,};
    level[index] = 0;
    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop_front();
        visited[cur] = true;
        for(int j=0;j<g[cur].size();j++)
        {
            if(!visited[g[cur][j]])
            {
                Q.push_back(g[cur][j]);
                level[g[cur][j]] = level[cur]+1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<"--"<<level[i]<<endl;
    }
}

int main()
{
    int V = 8;
    vector<int> graph[V]; 
    graph[0].push_back(1); 
    graph[0].push_back(2); 
    graph[1].push_back(3); 
    graph[1].push_back(4); 
    graph[1].push_back(5); 
    graph[2].push_back(5); 
    graph[2].push_back(6); 
    graph[6].push_back(7); 
    printLevel(graph, V, 0); 
    return 0;
}
