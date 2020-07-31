#include<bits/stdc++.h>
using namespace std;

using Node = struct Node{
    int data;
    struct Node * l;
    struct Node * r;
    struct Node * next;//For Connecting Next Nodes
    int hd;//For Top View & Buttom View
};

void insert(Node ** root,int data)
{
    Node * cur = new Node;
    cur->data = data;
    cur->l = cur->r = NULL;
    cur->next = NULL;
    cur->hd = 0;
    *root = cur;
}
//Just to Print Tree Using MorrisTravesal 
void inorder(Node * root)
{
    while(root)
    {
        if(!root->l)
        {
            cout<<root->data<<"--";
            root = root->r;
        }
        else
        {
            Node * prev = root->l;
            for(;prev->r!=root && prev->r!= NULL;prev = prev->r);
            if(!prev->r)
            {
                prev->r = root;
                root = root->l;
            }
            else
            {
                prev->r = NULL;
                cout<<root->data<<"--";
                root = root->r;
            }
        }
    }
}
void bottomView(Node *cur)
{
    if(!cur) return;
    Node * root = cur;
    map<int,int> m;
    root->hd = 0;
    list<Node*> Q;
    Q.push_back(root);
    while(!Q.empty())
    {
        Node * temp = Q.front(); 
        Q.pop_front();
        m[temp->hd] = temp->data;
        if(temp->l)
        {
            temp->l->hd = temp->hd - 1;
            Q.push_back(temp->l);
        }
        if(temp->r)
        {
            temp->r->hd = temp->hd + 1;
            Q.push_back(temp->r);
        }
    }
    map<int,int>::iterator mi = m.begin();
    for(;mi!=m.end();mi++)
    {
        cout<<mi->second<<"--";
    }
    cout<<endl;
}
int main()
{
    Node * root = NULL;
    insert(&root,5);
    insert(&root->l,3);
    insert(&root->r,7);
    insert(&root->l->l,2);
    inorder(root);
    bottomView(root);
    return 0;
}
