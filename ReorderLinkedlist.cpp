#including<bits/stdc++.h>
using namespace std;

using lst = struct lst{
    int data;
    lst *next;
};

void insertl(lst **root, int data)
{
    lst * cur = new lst;
    cur->data = data;
    cur->next = *root;
    *root = cur;
}
void printl(lst * root)
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
void reorder(lst * root)
{
    lst *cur = root;
    if(!cur) return;
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
    printl(cur);
}
int main()
{
    lst * root = NULL;
    insertl(&root,6);
    insertl(&root,5);
    insertl(&root,4);
    insertl(&root,3);
    insertl(&root,2);
    insertl(&root,1);
    printl(root);
    reorder(root);
    return 0;
}
