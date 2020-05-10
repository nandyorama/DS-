#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    struct Node *l;
    struct Node *r;
};
struct Node * newNode(char d)
{
    struct Node * cur = new struct Node;
    cur->data = d;
    cur->l = cur->r = NULL;
    return cur;
}
struct Node * createNode(string s, int &i)
{
    struct Node * cur = newNode(s[i]);
    if(i==s.length()-1) 
        return cur;
    i++;
    if(s[i]=='?')
    {
        i++;
        cur->l = createNode(s,i);
        i++;
        cur->r = createNode(s,i);
        return cur;
    }
    else
        return cur;
}
void print(struct Node *root)
{
    if(root)
    {
        print(root->l);
        cout<<root->data<<"--";
        print(root->r);
    }
}
int main()
{
    string s[] ={"a?b?c:d:e" , "a?b:c"};
    int n = sizeof(s)/sizeof(s[0]);
    for(int i =0;i<n;i++)
    {
        int iter =0;
        Node * cur = createNode(s[i],iter);
        print(cur);
        cout<<endl;
    }
    return 0;
}
