#include<bits/stdc++.h>
using namespace std;

void dfsUsingRecursion(int input)
{
    visited[input] = true;
    cout<<input<<"--";
    for(auto i=g[input].begin();i!=g[input].end();i++)
    {
        if(!visited[*i])
        {
            dfsUsingRecursion(*i);
        }
    }
}

int main()
{
  visited.assign(n, false); 
  g.assign(n, vector<int>());
  edge(0,1);
  edge(0,2);
  edge(0,3);
  edge(0,4);
  edge(3,5);
  for(int i=0;i<n;i++)
  {
    if(!visited[i])  
    {
        dfsUsingRecursion(i);             
    }
  }
  return 0;
}
