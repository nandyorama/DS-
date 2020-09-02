#include<bits/stdc++.h>
using namespace std;
void enQueue(list<int> &s,int data)
{
    s.push_back(data);
}
int deQueue(list<int> &s)
{
    if(s.empty())
    {
        cout<<"Q is empty"<<endl;
        return -1;
    }
    int x = s.back();
    s.pop_back();
    if(s.empty())
    {
        return x;
    }
    int temp = deQueue(s);
    s.push_back(x);
    return temp;
}
int main()
{
    list<int> s;
    enQueue(s,3);
    enQueue(s,2);
    enQueue(s,1);
    cout<<deQueue(s)<<endl;
    cout<<deQueue(s)<<endl;
    enQueue(s,4);
    cout<<deQueue(s)<<endl;
    cout<<deQueue(s)<<endl;
    cout<<deQueue(s)<<endl;
    return 0;
}
