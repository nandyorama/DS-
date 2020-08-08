#include<bits/stdc++.h>
using namespace std;
using Node = struct{
  int a;int b;  
};

void print(Node *root,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<root[i].a<<"---"<<root[i].b<<endl;
    }
    cout<<endl;
}

bool cmpUsingSecondElement(Node x, Node y)
{
    return x.b < y.b;
}

bool cmpUsingFirstElement(Node x, Node y)
{
    return x.a < y.a;
}

void sortElementOfNode(Node * input,int n)
{
    cout<<n<<endl;
    sort(input,input+n,cmpUsingSecondElement);
    print(input,n);
    sort(input,input+n,cmpUsingFirstElement);
    print(input,n);
}

int main()
{
    Node  root[] ={{3,5},{1,3},{4,2},{2,1}};
    int n = sizeof(root)/sizeof(root[0]);
    sortElementOfNode(root,n);
    return 0;
}
