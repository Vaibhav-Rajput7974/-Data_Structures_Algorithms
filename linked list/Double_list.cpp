#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* pre;
    node* next;
    node(int val)
    {
        data=val;
        pre=NULL;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
    {
        head->pre=n;
    }
    head=n;
}
void insertAtTell(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->pre=temp;
}
void deleteAtHead(node* &head)
{
    node* todel=head;
    head=head->next;
    head->pre=NULL;
    delete todel;
}
void deleting(node* &head,int pos)
{
    node* temp=head;
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }
    int count=1;
    while(temp!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    temp->pre->next=temp->next;
    if(temp->next==NULL)
    {
    temp->next->pre=temp->pre;
    }
    delete temp;
    return;

}
void display(node* head)
{
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}

int main()
{
    node* head=NULL;
    insertAtTell(head,1);
    insertAtTell(head,4);
    insertAtTell(head,7);
    insertAtTell(head,3);
    insertAtHead(head,0);
    deleting(head,1);
    display(head);
    return 0;
}