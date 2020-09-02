#include<iostream>
#include<map>
using namespace std;
struct list{
  int data;
  struct list *next;
  struct list *random;
};
void insert(struct list **root,int data)
{
    struct list * cur = new struct list;
    cur->data = data;
    cur->next=*root; 
    cur->random = NULL;
    *root = cur;
}
void print(struct list *root)
{
    while(root)
    {
        cout<<root->data<<"--";
        root = root->next;
    }
}
struct list * newList(int data)
{
    struct list * cur = new struct list;
    cur->data = data;
    cur->next = cur->random = NULL;
    return cur;
}
struct list * getClone(struct list *root)
{
    if(!root)
     return NULL;
    
    struct list * cur = root;
    struct list * result = newList(cur->data);
    struct list * temp = result;
    cur = cur->next;
    while(cur)				//Create New Clone List from Original List
    {
        result->next = newList(cur->data);
        result = result->next;
        cur = cur->next;
    }
    result->next = NULL;
    
    cur = root;
    map<struct list *,struct list *> mlist;
    while(cur)				//Keep Original List Next Pointer
    {
        mlist[cur]= cur->next;
        cur = cur->next;
    }
    
    result = temp;
    cur = root;
    while(cur && result)	//Original List next pointer pointing to new list & new list random pointer pointing to Original list	
    {
        struct list * aux = cur->next;
        cur->next = result;
        result->random = cur;
        cur = aux;
        result = result->next;
    }
    
    result = temp;
    while(result)			//new list random pointing to proper pointer
    {
        result->random = result->random->random->next;
        result = result->next;
    }
    
    cur=root;
    map<struct list*,struct list*>::iterator it;

    while(cur)				//Restoring Original list
    {
	    it=mlist.find(cur);
	    cur->next=it->second;
	    cur=cur->next;
    }
    
    return temp;
}
struct list * getCloneUsingHash(struct list *root) //Using Hashing 
{
    map<struct list*,struct list*> mp;
    struct list * cur = root;
    struct list * result = NULL;
    while(cur)//Create New Clone List from Original List and keep Original and new list in Map as Key, Value
    {
        insert(&result,cur->data);
        mp[cur]= result;
        cur = cur->next;
    }
    cur = root;
    
    map<struct list*,struct list*>::iterator mpi;
    while(cur)//Traverse Original list and make new list next and random pointer
    {
        mpi = mp.find(cur);
        result = mpi->second;
        mpi = mp.find(cur->next);
        result->next = mpi->second;
        mpi = mp.find(cur->random);
        result->random = mpi->second;
        cur = cur->next;
    }
    result->next = NULL;
    cur = root;
    mpi = mp.find(cur);
    return mpi->second;
}
int main()
{
	struct list *root=NULL;
	insert(&root,15);
	insert(&root,14);
	insert(&root,13);
	insert(&root,12);
	insert(&root,11);
	root->random=root->next->next;
	root->next->random=root;
	root->next->next->random=root->next->next->next->next;
	root->next->next->next->random=root->next->next;
	root->next->next->next->next->random=root->next;
	cout<<endl<<"print data of original list"<<endl;
	print(root);
	cout<<endl<<"print Clone list is "<<endl;
	struct list *root2=getCloneUsingHash(root);
	print(root2);
	cout<<endl<<root->random->data;
	cout<<endl<<root2->random->data;
	return 0;
}
