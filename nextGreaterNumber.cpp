#include<bits/stdc++.h>
using namespace std;

//Print elements of given array
void print(vector<int> v)
{
    for(auto i:v)
    {
        cout<<i<<"--";
    }
    cout<<endl;
}
//swap Two numbers of an array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Reverse elemts from index 's' to 'e'
void reverse(vector<int>& v,int s,int e)
{
    while(s<e)
    {
        v[s] ^= v[e];
        v[e] ^= v[s];
        v[s] ^= v[e];
        s++;e--;
    }
}
void nextGreaterNumber(vector<int> v)
{
    int n = v.size();
    int index = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(v[i]>v[i-1])
        {
            index = i-1;
            break;
        }
    }
    if(index<0)
    {
        cout<<"No Greater number"<<endl; 
        return;
    }
    int next = 0;
    int j = index;
    
    int max = INT_MAX;
    for(int i=index+1;i<n;i++)
    {
        if(v[i]-v[j]<max)
        {
            max = v[i]-v[j];
            next = i;
        }
    }
    swap(&v[index],&v[next]);
    reverse(v,index+1,n-1);
    print(v);
}
int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(9);
    v.push_back(8);
    v.push_back(7);
    v.push_back(6);
    print(v);
    nextGreaterNumber(v);
    return 0;
}
