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
node* append(node* &head,int k)
{
    if(head->next==NULL || k==0|| head==NULL)
    return head;
    node* new_head;
    node* new_tell;
    node *temp=head;
    int count=1;
    while(temp->next!=NULL)
    {
        if(count==k)
        {
            new_tell=temp;
            new_head=temp->next;
        }
        temp=temp->next;
        count++;
    }
    temp->next=head;
    new_tell->next=NULL;
    return new_head;
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
    node* newhead=append(head,2);
    display(newhead);
    return 0;
}