#include<bits/stdc++.h>
using namespace std;
int print(int *input, int n)
{
    int L[n]={0,};
    int R[n]={0,};
    L[0] = input[0]; R[n-1]=input[n-1];
    for(int i=1;i<n;i++)
    {
        L[i] = min(input[i], L[i-1]);
    }
    for(int i=n-2;i>=0;i--)
    {
        R[i] = max(input[i], R[i+1]);
    }
    int i =0,j =0, result=-1;
    for(;i<n && j<n;)
    {
        if(L[i]<R[j])
        {
            result = max(result, j-i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return result;
}
int main()
{
    int k[] = {1,2,3,4,5};
    int n = sizeof(k)/sizeof(k[0]);
    cout<<print(k,n);
    return 0;
}
