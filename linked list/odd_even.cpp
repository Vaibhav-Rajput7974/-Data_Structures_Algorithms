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
void odd_even(node* &head)
{
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;
    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenstart;
    if(odd->next!=NULL)
    {
        even->next=NULL;
    }
    return;

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
    odd_even(head);
    display(head);
    return 0;
}