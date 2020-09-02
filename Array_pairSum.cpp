#include<bits/stdc++.h>
using namespace std;
#define N 2
#define M 5
int numberOfPairWithGivenSum(int arr[], int n, int k) {
    int H[256]={0,};
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(H[k-arr[i]])
        {
            count+=H[k-arr[i]];
        }
        H[arr[i]]++;
    }
    return count;
}
int main()
{
    int inputSum = 6; 
    int a[N][M] = {
                 {1,2,3,4,3},
                 {5,3,3,1,3}
                 };
    for(int i=0;i<N;i++)
    {
        int n = sizeof(a[i])/sizeof(a[i][0]);
        cout<<numberOfPairWithGivenSum(a[i],n,inputSum)<<endl;
    }
    return 0;
}
