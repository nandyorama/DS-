#include<bits/stdc++.h>
using namespace std;
int minJump(int * a,int n)
{
    int res[n]={0,};
    res[0] = 0;
    for(int i=1;i<n;i++)
    {
        res[i] = INT_MAX;
        for(int j =0;j<i;j++)
        {
            if(i<=j+a[j])//
            {
                res[i] = min(res[i],res[j]+1);
            }
        }
    }
    return res[n-1];
}
int main()
{
    int a[]={2,1,3,1,1,2};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<minJump(a,n);
    return 0;
}
