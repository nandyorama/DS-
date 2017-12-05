#include<iostream>
using namespace std;
#include<list>
int getMaxAreaInHistogram(int *arr,int n)
{
    list<int> lindex;//Used STL list property as Stack 
    int i =0;
    int res = 0,area =0;
    while(i<n)
    {
        if(lindex.empty() || arr[lindex.back()]<arr[i])
         lindex.push_back(i++);
        else
        {
            int index = lindex.back();
            lindex.pop_back();
            area = arr[index] * (lindex.empty()?i:i-lindex.back()-1);
            if(res<area)
             res = area;
        }
    }
    
    while(!lindex.empty())
    {
        int index = lindex.back();
        lindex.pop_back();
        area = arr[index] * (lindex.empty()?i:i-lindex.back()-1);
        if(res<area)
         res = area;
    }
    
    return res;
}
int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Histogram Maximum area is " << getMaxAreaInHistogram(hist, n);
    return 0;
}
