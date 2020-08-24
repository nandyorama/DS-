#include<bits/stdc++.h>
using namespace std;
using Node = struct Node{
    int data;
    struct Node * l;
    struct Node * r;
};
void insert(Node ** root,int data)
{
    Node * cur = new Node;
    cur->data = data;
    cur->l = cur->r = NULL;
    *root = cur;
}

void inorderWithStack(Node * root)
{
    if(!root) return;
    list<Node *> S;
    while(1)
    {
        if(root)
        {
            S.push_back(root);
            root = root->l;
        }
        else
        {
            if(S.empty())
             break;
            Node * temp = S.back();
            S.pop_back();
            cout<<temp->data<<"--";
            if(temp->r)
            S.push_back(temp->r);
        }
    }
}
void in(Node * root)
{
    if(root)
    {
      in(root->l);
      cout<<root->data<<"--";
      in(root->r);
    }
}
void inorderWithoutStack&Recursion(Node * root)
{
    if(!root) return;
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
            for(;prev->r!=NULL && prev->r!=root;prev=prev->r);
            if(!prev->r)
            {
                prev->r = root;
                root = root->l;
            }
            else
            {
                cout<<root->data<<"--";
                prev->r = NULL;
                root = root->r;
            }
        }
    }
}
//Using Inorder Recursion
bool checkBSTUtil(Node * root, int *n)
{
    if(root)
    {
        checkBSTUtil(root->l,n);
        if(root->data < *n)
        {
            return 0;
        }
        *n = root->data;
        checkBSTUtil(root->r,n);
    }
    return 1;
}
bool checkBST(Node * root)
{
    int i = 0;//
    return checkBSTUtil(root,&i);
}
//Using Inorder without Recursion & Stack
void kthMax(Node * root,int k)
{
    if(!root) return;
    int i = 0;
    while(root)
    {
        if(!root->l)
        {
            i++;
            if(i==k) cout<<root->data<<"--";
            root = root->r;
        }
        else
        {
            Node * prev = root->l;
            for(;prev->r!=NULL && prev->r!=root;prev=prev->r);
            if(!prev->r)
            {
                prev->r = root;
                root = root->l;
            }
            else
            {
                i++;
                if(i==k) cout<<root->data<<"--";
                prev->r = NULL;
                root = root->r;
            }
        }
    }
    cout<<endl;
}

//Using Inorder
void swapNodesUtil(Node *root,Node** f, Node ** l,Node** m,Node ** prev)
{
    if(root)
    {
        swapNodesUtil(root->l,f,l,m,prev);
        if(*prev && root->data < (*prev)->data)
        {
            if(!*f)
            {
                *f = *prev;
                *m = root;
            }
            else
                *l = root;
        }
        
        *prev = root;
        swapNodesUtil(root->r,f,l,m,prev);
    }
}
void swapValue(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapNodes(Node * root)
{
    Node *f, *prev, *l, *m;
    f = prev = m = l = NULL;
    swapNodesUtil(root,&f,&l,&m,&prev);
    if(f && l)
    {
        swapValue(&(f->data),&(l->data));
    }
    else if(f && m)
    {
        swapValue(&(f->data),&(m->data));
    }
}
//Convert BST to DLL
void bst2DLL(Node *root, Node **head)
{
    if(!root) return;
    static Node * prev = NULL;
    bst2DLL(root->l,head);
    if(!prev)
    {
        *head = root;
    }
    else
    {
        root->l = prev;
        prev->r = root;
    }
    prev = root;
    bst2DLL(root->r,head);
}
void printDLL(Node * root)
{
    Node * head = root;
    while(head)
    {
        cout<<head->data<<"--";
        head = head->r;
    }
}
int main()
{
    Node * root = NULL;
    insert(&root,5);
    insert(&root->l,2);
    insert(&root->l->l,1);
    insert(&root->l->r,3);
    insert(&root->l->r->r,4);
    insert(&root->r,8);
    insert(&root->r->l,6);
    insert(&root->r->r,15);
    
    cout<<"InOrder Using Recursion---";in(root);cout<<endl;
    cout<<"InOrder Using Stack---";inorderWithStack(root);cout<<endl;
    cout<<"InOrder Without using Recursion & Stack---";inorderWithoutStack&Recursion(root);cout<<endl;
    cout<<"Check if BST or not -";checkBST(root)?cout<<"YES BST"<<endl:cout<<"NO BST"<<endl;
    cout<<"kthMax Node in given Tree is ---";kthMax(root,2);
    
    Node * root1 = NULL;
    insert(&root1,1);
    insert(&root1->l,2);
    insert(&root1->r,3);

    cout<<"Before SWAP InOrder-";in(root1);cout<<endl;
    swapNodes(root1);
    cout<<"After SWAP InOrder-";in(root1);cout<<endl;

    Node *head = NULL;
    bst2DLL(root, &head);
    printDLL(root);
    return 0;
}
