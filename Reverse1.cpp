#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node
{
    int data;
    Node* link;
};

void lst(Node** head_ptr,Node** tail_ptr,int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->link=NULL;
    if(*head_ptr==NULL)
    {
        *head_ptr=temp;
        *tail_ptr=temp;
    }
    else
    {
        (*tail_ptr)->link=temp;
        *tail_ptr=temp;
    }
    return ;
}

Node* fro(Node** head2_ptr, Node** tail2_ptr,int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->link=*tail2_ptr;
    *tail2_ptr=temp;
    return temp;
}

void make(Node* edge,Node** head2_ptr, Node** tail2_ptr,int k)
{
    Node* temp,*tempo1;
    Node* tempo2=NULL;
    int i,flag=1;
    while(edge!=NULL)
    {
        for(i=0;i<k;i++)
        {
            temp=fro(head2_ptr,tail2_ptr,edge->data);
            edge=edge->link;
            if(i==0)
            {
                tempo1=temp;
            }
        }
        if(flag==1)
        {
            *head2_ptr=*tail2_ptr;
            flag=0;
        }
        if(tempo2!=NULL)
        tempo2->link=temp;
        *tail2_ptr=NULL;
        tempo2=tempo1;
    }
    return ;
}

void Print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->link;
    }
    return ;
}

int main()
{
    ll n,i,x,k;
    cin>>n;
    Node* head1=NULL;
    Node* tail1=NULL;
    Node* head2=NULL;
    Node* tail2=NULL;
    for(i=0;i<n;i++)
    {
        cin>>x;
        lst(&head1,&tail1,x);
    }
    cin>>k;
    make(head1,&head2,&tail2,k);
    Print(head2);
}

//input array: 1 2 3 4 5 6
//output array: 3 2 1 6 5 4
