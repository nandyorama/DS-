#include<bits/stdc++.h>
using namespace std;
using Tree = struct Tree{
  int data;
  struct Tree * l;
  struct Tree * r;
};

void insert(Tree ** root, int data)
{
    Tree * cur = new Tree;
    cur->data = data;
    cur->l = cur->r = NULL;
    *root = cur;
}

void preOrder(Tree * root)
{
    Tree * cur = root;
    if(cur)
    {
        cout<<cur->data<<"--";
        pre(cur->l);
        pre(cur->r);
    }
    cout<<endl;
}

void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"--";
    }
    cout<<endl;
}

void root2leafUtil(Tree * root, int *arr,int n)
{
    if(!root) return;
    Tree * cur = root;
    arr[n++] = cur->data;
    if(!cur->l && !cur->r)
    {
        print(arr,n);
        return;
    }
    root2leafUtil(cur->l,arr,n);
    root2leafUtil(cur->r,arr,n);
}

void root2leaf(Tree * root)
{
    int result[]={0,};
    root2leafUtil(root,result,0);
}

int main()
{
    Tree * root = NULL;
    insert(&root,5);
    insert(&root->l,3);
    insert(&root->r,7);
    preOrder(root);
    root2leaf(root);
    return 0;
}
