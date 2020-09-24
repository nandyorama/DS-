#include<bits/stdc++.h>
using namespace std;
using Node = struct Node{
  int data;
  struct Node * next;
};
void insert(Node **root, int data)
{
    Node * cur = new Node;
    cur->data = data;
    cur->next = *root;
    *root = cur;
}
Node * sort2Sorted(Node *a,Node *b)
{
    if(!a)
    {
        return b;
    }
    else if(!b)
    {
        return a;
    }
    else{
        if(a->data < b->data)
        {
            a->next = sort2Sorted(a->next,b);
            return a;
        }
        else
        {
            b->next = sort2Sorted(a,b->next);
            return b;
        }
    }
}
void split(Node *root, Node **a,Node **b)
{
    if(!root || !root->next)
    {
        *a = root;
        *b = NULL;
    }
    else
    {
        Node * s = root;
        Node * f = root->next;
        while (f != NULL) 
        { 
            f = f->next; 
            if (f != NULL) 
            { 
                s = s->next; 
                f = f->next; 
            } 
        } 
        *a = s->next;
        s->next = NULL;
        *b = root;
    }
}
void print(Node * root)
{
    Node * cur = root;
    while(cur)
    {
        cout<<cur->data<<"--";
        cur = cur->next;
    }
    cout<<endl;
}
Node * mergesort(Node * root)
{
    if(!root || !root->next)
    {
        return root;
    }
    else
    {
        Node *a;Node *b;
        split(root,&a,&b);
        //print(a);
        //print(b);
        mergesort(a);
        mergesort(b);
        root = sort2Sorted(a,b);
    }
    return root;
}
int main()
{
    Node * root = NULL;
    insert(&root,6);
    insert(&root,4);
    insert(&root,5);
    insert(&root,8);
    insert(&root,1);
    print(root);
    Node * cur = mergesort(root);
    print(cur);
    return 0;
}
