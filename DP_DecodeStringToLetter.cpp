#include<bits/stdc++.h>
using namespace std;
int decodeStringToLetter(string input)
{
    int n = input.length();
    if(input[0]=='0') return -1;
    int result[n]={0,};
    result[0] = result[1] = 1;
    for(int i=2;i<=n;i++)
    {
        if(input[i-1]>'0')
         result[i] = result[i-1];
        if(input[i-2]=='1' || (input[i-2]=='2' && input[i-1]<'7'))
         result[i] += result[i-2];
    }
    return result[n];
}
//UseCases
//"123"
//i=2 result=1 2 
//i=3 result=2 3

//"456"
//i=2 result=1 
//i=3 result=1

//"2113"
//i=2 result=1 2 
//i=3 result=2 3 
//i=4 result=3 5 
int main()
{
    string s[] = {"123","456","111","2113","0123"};
    int n = sizeof(s)/sizeof(s[0]);
    for(int i =0;i<n;i++)
    {
        cout<<decodeStringToLetter(s[i])<<endl;            
    }
    return 0;
}
