#include<bits/stdc++.h>
using namespace std;
#define MAX 5
int Util(int *a,int s,int e)
{
    if(s>e) return -1;
    if(s==e) return s;
    int m = (s+e)/2;
    if(e>m && a[m]>a[m+1])
        return m;
    if(s<m && a[m]<a[m-1])
        return m-1;
    if(a[s]>a[m])
        return Util(a,s,m-1);
    else
        return Util(a,m+1,e);
}

int pivotElement(int *a,int n)
{
    return Util(a,0,n-1);
}

int main()
{
    int a[][MAX]={ 
                 {5,1,2,3,4},
                 {4,5,1,2,3},
                 {3,4,5,1,2},
                 {2,3,4,5,1},
                 {1,2,3,4,5}
               };
    int m = sizeof(a)/sizeof(a[0]);           
    for(int i=0;i<m;i++)
    {
        int n = sizeof(a[i])/sizeof(a[0][0]);
        cout<<pivotElement(a[i],n)<<endl;   
    }
    return 0;
}
