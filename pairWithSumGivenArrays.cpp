#include<bits/stdc++.h>
using namespace std;
void pairWithSum(int * a1, int * a2,int n,int m, int x)
{
    bool hash[100]={0,};
    for(int i =0;i<n;i++)
    {
        if(!hash[a1[i]])
            hash[a1[i]] = true;
    }
    for(int i =0;i<m;i++)
    {
        if(hash[abs(x-a2[i])])
         cout<<a2[i] <<"--"<< x-a2[i]<<endl;
    }
}
int main()
{
    int arr1[] = { 1, 0, -4, 7, 6, 4 }; 
    int arr2[] = { 0, 2, 4, -3, 2, 1 }; 
    int x = 8;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    pairWithSum(arr1,arr2,n,m,x);
    return 0;
}
