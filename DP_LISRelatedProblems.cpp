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
                result[i] = result[j]+1;
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

int MaxSUMIncreasingOrder(int * arr,int n)
{
    int res[n+1];
    for(int i =0;i<n;i++)
    res[i] = arr[i];
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<i;j++)
        {
            if(arr[i]>arr[j] && res[i]<res[j]+arr[i])
            res[i] = res[j]+arr[i];
        }
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        if(result<res[i])
         result = res[i];
    }
    return result;
}

struct Pair  
{ 
    int x;  
    int y;  
};  

int maxChain( Pair arr[], int n)  
{  
    int max = 0;  
    std::vector<int> result(n,1);  
    for (int i = 1; i < n; i++ )  
    {
        for (int j = 0; j < i; j++ )  
        {
            if ( arr[i].x > arr[j].y && result[i] < result[j] + 1)  
                result[i] = result[j] + 1;  
        }       
    }
    for (int i = 0; i < n; i++ )  
    {
        if ( max < result[i] )  
            max = result[i];  
    } 
    return max;  
}  

void print(vector<int> a)
{
    for(auto i: a)
    {
        cout<<i<<"**";
    }
    cout<<endl;
}
int LIB(int * arr,int n)
{
    vector<int> resLR(n,1);
    vector<int> resRL(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && resLR[i]<1+resLR[j])
            resLR[i] = 1+resLR[j];
        }
    }
    //print(resLR);
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j] && resRL[i]<1+resRL[j])
            resRL[i] = 1+resRL[j];
        }
    }
    //print(resRL);
    int max = resLR[0] + resRL[0] - 1;
    for(int i=1;i<n;i++)
    {
        if(resLR[0] + resRL[0] - 1 > max)
        {
            max = resLR[0] + resRL[0] - 1;
        }
    }
    return max;
}

int main()
{
    int a[]={1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<LIS(a,n);//Output-4
    
    cout<<endl<<MaxSUMIncreasingOrder(a,n)<<endl;//106
    
    Pair arr[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };  
    n = sizeof(arr)/sizeof(arr[0]);  
    cout << "Maximum size chain is " << maxChain(arr, n); //Output=3
    
    int ar[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}; 
    n = sizeof(ar)/sizeof(ar[0]); 
    cout<<LIB(ar,n);//Output-7

    return 0;
}
