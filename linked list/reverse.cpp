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
node* reverse(node* &head)
{
    node* prevese=NULL;
    node* current=head;
    node* nex;
    while(current!=NULL)
    {
        nex=current->next;
        current->next=prevese;

        prevese=current;
        current=nex;
    }
    return prevese;
}

node* reverseRecurssive(node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* newhead=reverseRecurssive(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return newhead;
}

node* reverseK(node* &head,int k)
{
    node* preptre=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k)
    { 
        nextptr=currptr->next;
        currptr->next=preptre;
        
        preptre=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
    
    head->next=reverseK( nextptr,k);
    }
    return preptre;
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

    //Function to check whether the list is palindrome.
    bool isPalindrome(node *head)
    {
        node* newhead=reverseRecurssive(head);
        node* temp=head;
        node* temp2=newhead;
        while(temp!=NULL && temp2!=NULL)
        {
            if(temp!=temp2)
            return false;
            temp=temp->next;
            temp2=temp2->next;
        }
        return true;
    }
int main()
{
    node* head=NULL;
    insertAtTell(head,1);
    insertAtTell(head,2);
    insertAtTell(head,2);
    insertAtTell(head,7);
    display(head);
    node* newhead=reverseRecurssive(head);

    display(newhead);
    return 0;
}