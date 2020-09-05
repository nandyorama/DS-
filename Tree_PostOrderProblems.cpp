#include<bits/stdc++.h>
using namespace std;
using Node = struct Node{
    int data;
    Node * l;Node *r;
};
void insert(Node **root, int data)
{
    Node * cur = new Node;
    cur->data = data;
    cur->l = cur->r = NULL;
    *root = cur;
}
void postOrder(Node * root)
{
    if(root)
    {
        postOrder(root->l);
        postOrder(root->r);
        cout<<root->data<<"-";
    }
}
void mirror(Node *root)
{
    if(root)
    {
        mirror(root->l);
        mirror(root->r);
        Node * temp = root->l;
        root->l = root->r;
        root->r = temp;
    }
}
int main()
{
    Node * root = NULL;
    insert(&root,5);
    insert(&root->l,3);
    insert(&root->r,7);
    insert(&root->r->l,6);
    postOrder(root);
    mirror(root);
    cout<<endl;
    postOrder(root);
    return 0;
}
