#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node
{
    int data;
    Node* link;
};

void Insert(Node** head_ptr,Node** tail_ptr,int x)
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

void fro(Node** head_ptr,int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->link=*head_ptr;
    *head_ptr=temp;
    return ;
}

void find(Node** head_ptr, Node* head1, Node* head2)
{
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            fro(head_ptr,head1->data);
            head1=head1->link;
        }
        else
        {
            fro(head_ptr,head2->data);
            head2=head2->link;
        }
    }
    while(head1!=NULL)
    {
        fro(head_ptr,head1->data);
        head1=head1->link;
    }
    while(head2!=NULL)
    {
        fro(head_ptr,head2->data);
        head2=head2->link;
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
    ll n,m,i,x;
    struct Node* head=NULL;
    struct Node* head1=NULL;
    struct Node* head2=NULL;
    struct Node* tail1=NULL;
    struct Node* tail2=NULL;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>x;
        Insert(&head1,&tail1,x);
    }
    for(i=0;i<m;i++)
    {
        cin>>x;
        Insert(&head2,&tail2,x);
    }
    find(&head,head1,head2);
    Print(head);
}
