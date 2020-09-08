#include<bits/stdc++.h>
using namespace std;
int maxTrappingWater(int *a,int n)
{
    int LR[n]={0,};
    int RL[n]={0,};
    LR[0] = a[0];
    for(int i=1;i<n;i++)
    {
        LR[i] = a[i]>LR[i-1]?a[i]:LR[i-1];
    }
    RL[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        RL[i] = a[i]>RL[i+1]?a[i]:RL[i+1];
    }
    int result = 0;
    for(int i=0;i<n;i++)
    {
        result += min(LR[i],RL[i])-a[i];//
    }
    return result;
}
int main()
{
  int input[]={3,1,0,2,1,3};
  int n = sizeof(input)/sizeof(input[0]);
  cout<<maxTrappingWater(input,n);
  return 0;
}
