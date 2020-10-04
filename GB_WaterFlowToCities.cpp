#include<bits/stdc++.h>
using namespace std;

int waterFlowUtil(int v[],vector<bool> visited,vector<int> edge[],int i)
{
    list<int> Q;
    Q.push_back(i);
    int count = 0;
    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop_front();
        visited[cur] = true;
        for(int j=0;j<edge[cur].size();j++)
        {
            if(!visited[edge[cur][j]] && !v[edge[cur][j]])
            {
                count++;
                Q.push_back(edge[cur][j]);
            }
            else if(!visited[edge[cur][j]] && v[edge[cur][j]])
            {
                count++;
            }
        }
    }
    return count+1;
} 

int waterFlow(int n,int v[],vector<int> edge[])
{
    vector<bool> visited(n,false);
    int max=1, res=0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0 && !visited[i]) {
            res = waterFlowUtil(v, visited, edge, i);
            if (res > max) {
                max = res;
            }
        }
    }     
    return max;
}

int main()
{
    int cities = 4; //Number of cities
    vector<int> edge[cities + 1];
    int v[cities + 1];
 
    //Connection between two cities
    edge[1].push_back(2);
    edge[2].push_back(1);
    edge[2].push_back(3);
    edge[3].push_back(2);
    edge[3].push_back(4);
    edge[4].push_back(3);
 
    //City is blocked or not
    v[1] = 0;
    v[2] = 1;
    v[3] = 1;
    v[4] = 0;
     
    cout<<waterFlow(cities, v, edge);
    return 0;
}
