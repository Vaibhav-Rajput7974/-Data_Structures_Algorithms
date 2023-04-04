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
        cout<<temp->data<<" "<<temp<<endl;
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
    display(head);
    return 0;
}