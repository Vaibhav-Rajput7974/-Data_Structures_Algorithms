#include<iostream>
using namespace std;
class node
{
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
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
bool search(node* head,int key)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==key)
        return true;

        temp=temp->next;
    }
    return false;
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
    insertAtTell(head,2);
    insertAtTell(head,2);
    insertAtHead(head,0);
    cout<<search(head,1)<<endl;
    display(head);
    return 0;
}