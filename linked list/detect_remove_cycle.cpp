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
void makecycle(node* &head,int pos)
{
    node* temp=head;
    node* startingnode;
    int count=0;
    while(temp->next!=NULL)
    {
        if(pos==count)
        {
            startingnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startingnode;
}
void detect_remove(node* head)
{
   node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(fast!=slow);

    fast=head;
    while(fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
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
    insertAtTell(head,3);
    insertAtTell(head,4);
    insertAtTell(head,5);
    insertAtTell(head,6);
    //cout<<search(head,1)<<endl;
    makecycle(head,1);
    detect_remove(head);
    display(head);
    return 0;
}