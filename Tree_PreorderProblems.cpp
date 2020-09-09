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
//Input
//  5
//2   6
//Output: 5--2 5--6
void root2leaf(Tree * root)
{
    int result[]={0,};
    root2leafUtil(root,result,0);
}
void UtilPrint(Tree * root, int cur, vector<int>& sum)
{
    if(!root) return;
    cur += root->data;
    if(!root->l && !root->r)
    {
        sum.push_back(cur);
    }
    UtilPrint(root->l,cur,sum);
    UtilPrint(root->r,cur,sum);
}
//Input
//  5
//2   6
//Output: 7 11
void printAllRoot2LeafPathSum(Tree * root)
{
    int cur = 0; vector<int> sum;
    UtilPrint(root,cur,sum);
    for(int item: sum)
    {
        cout<<item<<"--";
    }
}
void maxSumFromRoot2LeafUtil(Tree * root,int cur, int *max)
{
    if(!root) return;
    cur += root->data;
    if(!root->l && !root->r && cur > *max)
    {
        *max = cur;
    }
    maxSumFromRoot2LeafUtil(root->l,cur,max);
    maxSumFromRoot2LeafUtil(root->r,cur,max);
}
//Input
//  5
//2   6
//Output: 11
void maxSumFromRoot2Leaf(Tree *root)
{
    int cur = 0; int maxSum = 0;
    maxSumFromRoot2LeafUtil(root,cur,&maxSum);
    cout<<endl<<maxSum<<endl;
}
int sumOfNodesRoot2LeafUtil(Tree * root,int n)
{
    if(!root) return 0;
    n = (n*10) + root->data;
    if(!root->l && !root->r)
    {
        return n;
    }
    return sumOfNodesRoot2LeafUtil(root->l,n)+
           sumOfNodesRoot2LeafUtil(root->r,n);
}
//Input
//  5
//2   6
//Output: 52 + 56 = 108
int sumOfNodesRoot2Leaf(Tree *root)
{
    return sumOfNodesRoot2LeafUtil(root,0);
}
int main()
{
    Tree * root = NULL;
    insert(&root,5);
    insert(&root->l,3);
    insert(&root->r,7);
    preOrder(root);
    root2leaf(root);
    maxSumFromRoot2Leaf(root);
    printAllRoot2LeafPathSum(root);
    sumOfNodesRoot2Leaf(root);
    return 0;
}
