#include<bits/stdc++.h>
using namespace std;
using Node = struct Node{
    int data;
    Node * next;
};
void insert(Node ** root,int data)
{
    Node * cur = new Node;
    cur->data = data;
    cur->next = *root;
    *root = cur;
}
void print(Node * root)
{
    while(root)
    {
        cout<<root->data<<"--";
        root = root->next;
    }
    cout<<endl;
}
Node * Util(Node *a , Node * b, int *carry)
{
    if(!a || !b)
    {
        return NULL;    
    }
    else
    {
        Node * cur = new Node;
        cur->next = Util(a->next,b->next,carry);
        int sum = a->data + b->data + *carry;
        cur->data = sum %10;
        *carry = sum/10;
        return cur;        
    }
}
Node * addNodesOfEqualSize(Node *a,Node *b)
{
    int carry = 0;
    Node * cur = Util(a,b,&carry);
    if(carry>0)
    insert(&cur,carry);
    return cur;
}
int count(Node *root)
{
    int count=0;
    while(root)
    {
        count++;
        root = root->next;
    }
    return count;
}
Node * add(Node *a ,Node *b)
{
    int n = count(a);
    int m = count(b);
    if(n==m)
    {
        return addNodesOfEqualSize(a,b);
    }
    else if(n>m)
    {
        int d = n-m;
        while(d--)
        {
            insert(&b,0);
        }
        print(b);
        return addNodesOfEqualSize(a,b);
    }
    else
    {
        int d = m-n;
        while(d--)
        {
            insert(&a,0);
        }
        print(a);
        return addNodesOfEqualSize(a,b);
    }
}
int main()
{
    Node * root = NULL;
    insert(&root,2);
    insert(&root,9);
    print(root);
    Node * root1 = NULL;
    insert(&root1,9);
    print(root1);
    Node * cur = add(root,root1);
    print(cur);
    return 0;
}
