#including<bits/stdc++.h>
using namespace std;

using lst = struct lst{
    int data;
    lst *next;
};

void insert(lst **root, int data)
{
    lst * cur = new lst;
    cur->data = data;
    cur->next = *root;
    *root = cur;
}
void print(lst * root)
{
    while(root)
    {
        cout<<root->data<<"--";
        root = root->next;
    }
    cout<<endl;
}
lst* reverse(lst *root)
{
    lst *cur = root;
    if(!cur) return NULL;
    lst * result = NULL;
    lst *temp;
    while(cur)
    {
        temp = cur->next;
        cur->next = result;
        result = cur;
        cur = temp;
    }
    return result;
}
lst * reorder(lst * root)
{
    lst *cur = root;
    if(!cur) return NULL;
    lst * sl = cur;
    lst * ft = cur;
    while(ft && ft->next)
    {
        sl = sl->next;
        ft = ft->next->next;
    }
    lst * rev  = reverse(sl);
    lst * head = cur;
    while(head && rev)
    {
        lst * a = head->next;
        lst * b = rev->next;
        head->next = rev;
        rev->next = a;
        rev = b;
        head = a;
    }
    if(head)
    head->next = NULL;
    
    return cur;
}
int main()
{
    lst * root = NULL;
    insert(&root,6);
    insert(&root,5);
    insert(&root,4);
    insert(&root,3);
    insert(&root,2);
    insert(&root,1);
    print(root);
    lst * result = reorder(root);
    print(result);
    return 0;
}
