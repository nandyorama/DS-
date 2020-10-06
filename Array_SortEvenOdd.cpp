#include<bits/stdc++.h>
using namespace std;
void sortevenodd(int * arr,int n)
{
    for(int i =0;i<n;++i)
    {
        if(arr[i]&1)
            arr[i] *= -1; 
    }
    sort(arr,arr+n);
    for(int i =0;i<n;++i)
    {
        if(arr[i]&1)
            arr[i] *= -1; 
    }
}
int main()
{
    int arr[] = {1, 3, 2, 7, 5, 4};
    int sz = sizeof(arr)/sizeof(arr[0]);
    sortevenodd(arr,sz);
    for(int i =0;i<sz;++i)
    {
        cout<<arr[i]<<"--";
    }
    getchar();
    return 0;
}


