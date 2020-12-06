#include<bits/stdc++.h>
using namespace std;
using T = struct T{
  int data;
  T * left;
  T * right;
};
void insert(T **root,int data)
{
    T * cur = new T;
    cur->data = data;
    cur->left = cur->right = NULL;
    *root = cur;
}

void in(T * root)
{
    if(root)
    {
        in(root->left);
        cout<<root->data<<" ";
        in(root->right);
    }
}
void topView(T * root) 
    {
        if(!root) return;
        map<int,int> m;
        list<T*> Q;
        Q.push_back(root);
    
        list<int> iQ;
        iQ.push_back(0);
        while(!Q.empty() && !iQ.empty())
        {
            T * cur = Q.front();
            Q.pop_front();
            
            int d = iQ.front();
            iQ.pop_front();
            
            if(m.find(d)==m.end())
            {
                m[d] = cur->data;
            }
            
            if(cur->left)
            {
                Q.push_back(cur->left);
                iQ.push_back(d-1);
            }
            if(cur->right)
            {
                Q.push_back(cur->right);
                iQ.push_back(d+1);
            }
        }
        map<int,int>::iterator mi = m.begin();
        for(;mi!=m.end();mi++)
        {
            cout<<mi->second<<" ";
        }
    }
int main()
{
    T * root = NULL;
    insert(&root,1);
    insert(&root->right,2);
    insert(&root->right->right,5);
    insert(&root->right->right->right,6);
    insert(&root->right->right->left,3);
    insert(&root->right->right->left->right,4);
    topView(root);
    return 0;
}
