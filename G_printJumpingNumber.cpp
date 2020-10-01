#include<bits/stdc++.h>
using namespace std;
//Using BFS
void jumpNumberUtil_Bfs(int i, int k)
{
    list<int> Q;
    Q.push_back(i);
    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop_front();
        if(cur<k)
        {
            cout<<cur<<"--";
            int last_digit = cur %10;
            if(last_digit == 0)
            {
                Q.push_back((cur*10) + (last_digit+1));
            }
            else if(last_digit == 9)
            {
                Q.push_back((cur*10) + (last_digit-1));
            }
            else
            {
                Q.push_back((cur*10) + (last_digit+1));
                Q.push_back((cur*10) + (last_digit-1));
            }
        }
    }
}
//using dfs
void jumpNumberUtil_Dfs(int i, int k)
{
    if(i<k)
    {
        cout<<i<<"--";
        int last_digit = i %10;
        if(last_digit == 0)
        {
            jumpNumberUtil_Dfs((i*10) + (last_digit+1),k);
        }
        else if(last_digit == 9)
        {
            jumpNumberUtil_Dfs((i*10) + (last_digit-1),k);
        }
        else
        {
            jumpNumberUtil_Dfs((i*10) + (last_digit-1),k);
            jumpNumberUtil_Dfs((i*10) + (last_digit+1),k);
        }
    }
}

void jumpNumber(int k)
{
    for(int i=1;i<=9;i++)
    {
        jumpNumberUtil_Bfs(i,k);
    }
    cout<<endl;
    for(int i=1;i<=9;i++)
    {
        jumpNumberUtil_Dfs(i,k);
    }
    cout<<endl;

}
int main()
{
    int k[] = {20,180};
    int n = sizeof(k)/sizeof(k[0]);
    for(int i=0;i<n;i++)
    {
        jumpNumber(k[i]);   
    }
    return 0;
}
