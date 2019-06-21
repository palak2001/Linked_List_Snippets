#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

void ins_fro(Node** head_ptr, int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->link=*head;
    *head_ptr=temp;
    return;
}

void ins_end(Node** head_ptr,Node** tail_ptr,int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->link=NULL;
    if(*head_ptr==NULL)
    {
        *head_ptr=temp;
    }
    *tail_ptr->link=temp;
    return;
}

void ins_node(Node** head_ptr,int m,int x)
{
    Node* temp=new Node();
    temp->data=x;
    while((*head_ptr)!=NULL)
    {
        if((*head_ptr)->data==m)
        {
            temp->link=(*head_ptr)->link;.
            (*head_ptr)->link=temp;
            break;
        }
        (*head_ptr)=(*head_ptr)->link;
    }
    return;
}

void Traverse(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
    }
}

int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    cin>>n;

    //Insertion at Front
    for(i=0;i<n;i++)
    {
        cin>>x;
        ins_fro(&head,x);
    }

    //Insertion at End
    for(i=0;i<n;i++)
    {
        cin>>x;
        ins_end(&head,&tail,x);
    }

    //Insertion after a node name m
    cin>>m>>x;
    ins_node(&head,m,x);

    //Traversing the linked list
    Traverse(head);
}