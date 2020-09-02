#include<bits/stdc++.h>
using namespace std;
int LIS(int *a,int n)
{
    int result[n];
    for(int i =0;i<n;i++)
     result[i] = 1;
    
    for(int i =1 ;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && result[i]<result[j]+1)
            {
                result[i] = res[j]+1;
            }
        }
    }
    int max = INT_MIN;
    for(int i =0 ;i<n;i++)
    {
        //cout<<res[i]<<"--";
        if(result[i]>max)
        {
            max = result[i];
        }
    }    
    //cout<<endl;
    return max;
}
int main()
{
    int a[]={4,5,1,3,4,9};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<LIS(a,n);
    return 0;
}
