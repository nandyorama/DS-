#include<bits/stdc++.h>
using namespace std;
int numberOfParentChildPair(int *a,int n)
{
    if(n<0) return -1;
    int H[256]={0,};
    int count = 0;
    for(int i=0;i<n;i++)
    {
        H[a[i]] = 1;
    }
    for(int i=0;i<n;i++)
    {
        if(H[a[i]+1])
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int a[]= {1,2,3,4};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<numberOfParentChildPair(a,n)<<endl;
    return 0;
}
