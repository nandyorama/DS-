#include<bits/stdc++.h>
using namespace std;
string expand(string input,int n)
{
    string result;
    int count=0;
    list<int> is;
    list<char> cs;
    for(int i =0;i<n;i++)
    {
        if(input[i]>='0' && input[i]<='9')
        {
            is.push_back(input[i]-'0');    
        }
        else if(input[i]==']')
        {
            string temp;
            if(!is.empty()) 
            {
                count = is.back();
                is.pop_back();
            }
            while(!cs.empty() && cs.back() != '[')
            {
                temp = cs.back()+temp;//Can use front as using list
                cs.pop_back();
            }
            if(!cs.empty() && cs.back() == '[')
            {
                cs.pop_back();
            }
            for(int i=0;i<count;i++)
            {
                result = temp+result;
            }
            if(!is.empty() && !cs.empty())
            {
                for(int i=0; i<result.length();i++)
                {
                    cs.push_back(result[i]);
                }                
                result="";
            }
        }
        else if(input[i]=='[')
        {
            if(input[i-1]>='0' && input[i-1]<='9')
            {
                cs.push_back(input[i]);
            }
        }
        else
        {
            cs.push_back(input[i]);
        }
    }
    return result;
}

int main()
{
    string input[] = {"2[a]","2[ab]","2[a2[b]]","2[[a]]"};
    int n = sizeof(input)/sizeof(input[0]);
    for(int i=0;i<n;i++)
    {
        cout<<expand(input[i],input[i].length())<<endl;
    }
    
    return 0;
}
