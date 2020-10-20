#include<iostream>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int kadaneDP(int * arr,int n)
{
    int cur = arr[0];
    int res = arr[0];
    for(int i=1;i<n;i++)
    {
        cur = max(arr[i], cur+arr[i]);
        res = max(cur,res);
    }
    return res;
}
int main()
{
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<kadaneDP(arr,n);
    return 0;
}
