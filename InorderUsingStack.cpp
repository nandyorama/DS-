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

void inorder(struct t * root)
{
    list<struct t*> li;//STL List used for stack  
    while(1)
    {
        if(root)
        {
            li.push_back(root);
            root = root->l;
        }
        else
        {
            if(li.empty())
                break;
            struct t * cur = li.back();
            li.pop_back();
            cout<<cur->data<<"--";
            if(cur->r)
                li.push_back(cur->r);
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
    cout<<"Inorder Using Stack"<<endl;
    inorder(root);
    return 0;
}
