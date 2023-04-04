#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertAtTell(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void delete_head(node* &head)
{
    node* temp=head;
    node* todelete=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    delete todelete;
    return;
}
void delete_node(node* &head,int pos)
{
    node* temp=head;
    int count=1;
    if(pos==1)
    {
        delete_head(head);
        return ;
    }
    while(count!=pos-1)
    {
        temp=temp->next;
        count++;
    }
    node* todelete;
    todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
void display(node* head)
{
    node* temp=head;
    
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while (temp!=head);
    
}
int main()
{
    node* head=NULL;
    insertAtTell(head,1);
    insertAtTell(head,2);
    insertAtTell(head,3);
    insertAtTell(head,4);
    insertAtTell(head,5);
    delete_node(head,1);
    display(head);
    return 0;
}