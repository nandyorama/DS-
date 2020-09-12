#include<bits/stdc++.h>
using namespace std;
#define MAX 256
bool IsValid(int *a,int k)
{
    int count = 0;
    for(int i =0;i<MAX;i++)
    {
        if(a[i]>1)
            count++;
    }
    return count>k;
}
void maxSubstring(string input,int k)
{
    int n = input.length();
    int ucount=0, cur_end=0, start=0, max_s=0, max_start=0;
    int H[MAX]={0,};
    for(int i=0;i<n;i++)
    {
        if(!H[input[i]-'a'])
        {
            ucount++;
        }
        H[input[i]-'a']++;
    }
    if(ucount<k)
    {
        cout<<"NOT FOUND"<<endl;
        return;
    }
    memset(H,0,sizeof(H));
    H[input[0]-'a']++;
    for(int i=1;i<n;i++)
    {
        H[input[i]-'a']++;
        cur_end++;
        if(IsValid(H,k))
        {
            H[input[start]-'a']--;
            start++;
        }
        if(cur_end-start+1 > max_s)
        {
            max_s = cur_end-start+1;
            max_start = start;
        }
    }
    cout<<input.substr(max_start,max_s);
}
int main()
{
    string s = "aabbcc";
    int k = 3;
    maxSubstring(s,k);
    return 0;
}
