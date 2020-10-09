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


int main()
{
    int a[]={1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<LIS(a,n);//4
    
    cout<<endl<<MaxSUMIncreasingOrder(a,n)<<endl;//106
    
    Pair arr[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };  
    n = sizeof(arr)/sizeof(arr[0]);  
    cout << "Maximum size chain is " << maxChain(arr, n); //Output=3
    return 0;
}
