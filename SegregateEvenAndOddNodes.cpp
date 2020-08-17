#include<bits/stdc++.h>
using namespace std;
using Node = struct Node{
    int data;
    struct Node * next;
};
void insert(Node ** root,int data)
{
    Node * cur = new Node;
    cur->data = data;
    cur->next = *root;
    *root = cur;
}
void print(Node * cur)
{
    Node * root = cur;
    while(root)
    {
        cout<<root->data<<"--";
        root = root->next;
    }
    cout<<endl;
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printEvenOddSeparately(Node * root)
{
    Node * cur = root;
    if(!cur) return;
    Node * temp = cur->next;
    bool even_1 = 0;bool even_2 = 0;
    while(cur && temp)
    {
        if(cur->data%2==0)
            even_1 = 1;
        else
            even_1 = 0;
            
        if(temp->data%2==0)
            even_2 = 1;
        else
            even_2 = 0;
            
        if(!even_1 && even_2)
        {
            swap(&cur->data , &temp->data);
            cur = cur->next;
            temp = temp->next;
        }
        else if(!even_1 && !even_2)
        {
            temp = temp->next;
        }
        else
        {
            temp = temp->next;
            cur = cur->next;
        }
    }
}
int main()
{
    Node * root = NULL;
    insert(&root,6);
    insert(&root,1);
    insert(&root,4);
    insert(&root,5);
    insert(&root,10);
    insert(&root,12);
    insert(&root,8);
    print(root);
    printEvenOddSeparately(root);
    print(root);
    return 0;
}
