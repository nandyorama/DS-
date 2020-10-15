#include<bits/stdc++.h>
using namespace std;
#define n 6
void edge(vector<vector<int>> &g,int a,int b)
{
    g[a].push_back(b);
}
void dfsUsingRecursion(vector<vector<int>> g,vector<bool>& visited,int input)
{
    visited[input] = true;
    cout<<input<<"--";
    for(auto i=g[input].begin();i!=g[input].end();i++)
    {
        if(!visited[*i])
        {
            dfsUsingRecursion(g,visited,*i);
        }
    }
}

void topology(vector<vector<int>> g, vector<bool>& visited, int input, list<int> &stack)
{
    visited[input] = true;
    
    for(auto i=g[input].begin();i!=g[input].end();i++)
    {
        if(!visited[*i])
        {
            topology(g,visited,*i,stack);
        }
    }
    stack.push_back(input);
}
int main()
{
  vector<bool> visited;
  vector<vector<int>> g;
    
  visited.assign(n, false); 
  g.assign(n, vector<int>());
  edge(g,0,1);
  edge(g,0,2);
  edge(g,0,3);
  edge(g,0,4);
  edge(g,3,5);
  
  for(int i=0;i<n;i++)
  {
    if(!visited[i])  
    {
        dfsUsingRecursion(g,visited,i);             
    }
  }
  cout<<endl;
  fill(visited.begin(),visited.end(),false);
  list<int> stack;
  for(int i=0;i<N;i++)
  {
    if(!visited[i])  
    {
       topology(g,visited,i,stack);             
    }
  }
  while(!stack.empty())
  {
      cout<<stack.back()<<"***";
      stack.pop_back();
  }
  
  return 0;
}
