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
void levelOrderTraversal(Node *root)
{
    if(!root) return;
    Node * cur = root;
    list<Node*> Q;
    Q.push_back(root);
    while(!Q.empty())
    {
        Node * temp = Q.front(); 
        Q.pop_front();
        cout<<temp->data<<"--";
        if(temp->l)
        {
            Q.push_back(temp->l);
        }
        if(temp->r)
        {
            Q.push_back(temp->r);
        }
    }
    cout<<endl;
}
void bottomView(Node *root)
{
    if(!root) return;
    Node * cur = root;
    map<int,int> m;
    cur->hd = 0;
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
void topView(Node *root)
{
    if(!root) return;
    Node * cur = root;
    map<int,int> m;
    cur->hd = 0;
    list<Node*> Q;
    Q.push_back(root);
    while(!Q.empty())
    {
        Node * temp = Q.front(); 
        Q.pop_front();
        if(m.find(temp->hd) == m.end())
        {
            m[temp->hd] = temp->data;
        }
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
void rightView(Node * root)
{
    if(!root) return;
    Node * cur = root;
    list<Node*> Q;
    Q.push_back(cur);
    while(!Q.empty())
    {
     int n = Q.size();
     for(int i = 1;i<=n;i++)
     {
         Node * temp = Q.front();
         Q.pop_front();
         if(i==n)
         {
             cout<<temp->data<<"--";
         }
         
         if(temp->l)
         {
             Q.push_back(temp->l);
         }
         if(temp->r)
         {
             Q.push_back(temp->r);
         }
     }
    }
    cout<<endl;
}
int main()
{
    Node * root = NULL;
    insert(&root,5);
    insert(&root->l,3);
    insert(&root->l->r,4);
    insert(&root->r,7);
    insert(&root->r->l,6);
    insert(&root->l->l,2);
    inorder(root);
    levelOrderTraversal(root);
    bottomView(root);
    rightView(root);
    topView(root);
    return 0;
}





















