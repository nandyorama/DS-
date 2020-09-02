#include <iostream>
#include<list>
using namespace std;

struct t{
  int data;
  struct t *l;
  struct t *r;
};

void insert(struct t **root,int data)
{
    struct t * cur = new struct t;
    cur->data = data;
    cur->l = cur->r = NULL;
    *root = cur;
}

void inorder(struct t *root)
{
    struct t * cur = root;
    while(cur)
    {
        if(cur->l==NULL)
        {
            cout<<cur->data<<"--";
            cur = cur->r;
        }
        else
        {
            struct t * prev = cur->l;
            for(;prev->r!=NULL&&prev->r!=cur;prev= prev->r);
            if(prev->r==NULL)
            {
                prev->r = cur;
                cur = cur->l;
            }
            else
            {
                prev->r = NULL;
                cout<<cur->data<<"--";
                cur = cur->r;
            }
        }
    }
}

int main()
{
    struct t * root = NULL;
    insert(&root,5);
    insert(&root->l,3);
    insert(&root->r,7);
    insert(&root->l->l,2);
    insert(&root->l->r,4);
    insert(&root->r->l,6);
    insert(&root->r->r,8);
    cout<<"Inorder Using Morris Travseral"<<endl;
    inorder(root);
    return 0;
}
