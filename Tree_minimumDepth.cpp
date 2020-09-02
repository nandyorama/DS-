#include<bits/stdc++.h>
using namespace std;
using Node = struct Node
{
    int data;
    struct Node * l;
    struct Node * r;
};
using NodeWithDepth = struct NodeWithDepth
{
    Node * root;
    int depth;
};
void newNode(Node **root,int data)
{
    Node * cur = new Node;
    cur->data = data;
    cur->l = cur->r = NULL;
    *root = cur;
}
void inOrder(Node * root)
{
    if(root)
    {
        inOrder(root->l);
        cout<<root->data;
        inOrder(root->r);
    }
}
int findMinimumDepth(Node *root)
{
    if(!root) return 0;
    NodeWithDepth node = {root,1};
    list<NodeWithDepth> Q;
    Q.push_back(node);
    while(!Q.empty())
    {
        NodeWithDepth temp = Q.front();
        if(!temp.root->l && !temp.root->r)
            return temp.depth;
        Q.pop_front();
        if(temp.root->l)
        {
            node.root = temp.root->l;
            node.depth = temp.depth + 1;
            Q.push_back(node);   
        }
        if(temp.root->r)
        {
            node.root = temp.root->r;
            node.depth = temp.depth + 1;
            Q.push_back(node);   
        }
    }
}
int height(Node * root)
{
    if(!root) return 0;
    if(!root->l && !root->r) return 1;
    return max(height(root->l),height(root->r))+1;
}
int main()
{
    Node * root = NULL;
    newNode(&root,3);
    newNode(&root->l,2);
    newNode(&root->r,4);
    newNode(&root->r->r,7);
    //inOrder(root);
    cout<<findMinimumDepth(root)<<endl;
    cout<<height(root)<<endl;
    return 0;
}
