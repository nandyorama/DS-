#include<bits/stdc++.h>
using namespace std;

using Interval=struct Interval{
  int start;int end;  
};
bool cmpInterval(Interval a,Interval b)
{
    return a.start < b.start;
}
void printInterval(vector<Interval> input)
{
    for(auto i: input)
    {
        cout<<i.start<<"---"<<i.end<<endl;
    }
    cout<<endl;
}
int mergedInterval(vector<Interval> input)
{
    int n = input.size();
    //Sort by start
    sort(input.begin(),input.end(),cmpInterval);
    Interval result[]={0};
    int index = 0;
    result[index] = input[0];
    for(int i=1;i<n;i++)
    {
        if(result[index].end > input[i].start)
        {
           result[index].end = result[index].end > input[i].end ? result[index].end : input[i].end;
           result[index].start = result[index].start < input[i].start ? result[index].start : input[i].start;
        }
        else
        {
            index++;
            result[index] = input[i];
        }
    }
    //printInterval(result);
    return index+1;
}
int main()
{
    vector<it> input={{2,15},{16,23},{36,45},{4,9},{9,29}};
    cout<<"Count Merged Intervals"<<mergedInterval(input)<<endl;
    return 0;
}
