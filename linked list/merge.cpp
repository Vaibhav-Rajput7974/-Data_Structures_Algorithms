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

node* merge(node* &head,node* &head2)
{
    node* temp1=head;
    node* temp2=head2;

    node* dumenode=new node(-1);
    node* temp3=dumenode;   

    while (temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            temp3->next=temp1;
            temp1=temp1->next;
        }
        else
        {
            temp3->next=temp2;
            temp2=temp2->next;
        }
        temp3=temp3->next;
    }
    while (temp2!=NULL)
    {
        temp3->next=temp2;
        temp2=temp2->next;
        temp3=temp3->next;
        
    }
    while (temp1!=NULL)
    {
        temp3->next=temp1;
        temp1=temp1->next;
        temp3=temp3->next;
    }
    return dumenode->next;
}

node* merge_reccursive(node* &head,node* &head2)
{
    node* result;
    if(head==NULL){
    return head2;     
    }
    
    if(head2==NULL){
    return head;
    }
    if(head->data<head2->data)
    {
        result=head;
        result->next=merge_reccursive(head->next,head2);
    }
    else
    {
        result=head2;
        result->next=merge_reccursive(head,head2->next);    
    }
    return result;
}
int main()
{
    node* head=NULL;
    insertAtTell(head,1);
    insertAtTell(head,4);
    insertAtTell(head,5);
    insertAtTell(head,7);
    display(head);
    node * head2=NULL;
    insertAtTell(head2,2); 
    insertAtTell(head2,6);
     display(head2);
    node* newhead=merge_reccursive(head,head2);
    display(newhead);
    return 0;
}