#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
     int size = nums.size();   
     vector<int> result(size,1);
     vector<int> lr(size,1);
     vector<int> rl(size,1);
     for(int i=1;i<size;i++)
     { 
        lr[i] = lr[i-1] *nums[i-1];
     }

     for(int i=size-2;i>=0;i--)
     { 
        rl[i] = rl[i+1] *nums[i+1];
     }
     
     for(int i=0;i<size;i++)
     { 
        result[i] = rl[i] *lr[i];
     }
     return result;   
}
int main()
{
    vector<int> ip = {1,2,3,4};
    vector<int> res = productExceptSelf(ip);
    for(int x: res)
    {
        cout<<x<<"--";
    }
    return 0;
}
