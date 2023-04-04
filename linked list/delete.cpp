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
void insertAtTell(node* &head,int val){
node* n=new node(val);
if(head==NULL)
{
    head=n;
    return;
}
node* temp=head;
while (temp->next!=NULL)
{
    temp=temp->next;
}
temp->next=n;
}
void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;

    delete todelete;
}
void deletes(int val,node* &head){
    if(head==NULL)
    return;

    if(head->next==NULL)
    deleteAtHead(head);
    node* temp=head;    
    while(temp->next->data!=val){
        
    temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
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
    insertAtTell(head,2);
    insertAtTell(head,4);
    insertAtTell(head,3);
    deletes(3,head);
    deleteAtHead(head);
    display(head);
}
