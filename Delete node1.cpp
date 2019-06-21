void deletenode(Node** head_ptr, int x)
{
    Node* temp=*head_ptr;
    Node* prev;

    //if starting node is to be deleted
    if(temp!=NULL&&temp->data==x)
    {
        temp=temp->next;
        return;
    }
    else
    {
        //find the node to be deleted if its not the first node
        //We must keep track of previous element so as to change the address in it pointing to the next node
        while(temp!=NULL&&temp->data!=x)
        {
            prev=temp;
            temp=temp->next;
        }
        //Deleting node and freeing the memory
        prev->next=temp->next;
        free(temp);
        return;
    }
}