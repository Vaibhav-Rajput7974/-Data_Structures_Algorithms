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
    node* temp=head;
    if(head==NULL)
    {
        head=n;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

int length_list(node* head)
{
    int len=0;
    if(head==NULL)
    return 0;
    while(head->next!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}
int intersect_point(node* &head,node* &head2)
{
    int l1=length_list(head);
    int l2=length_list(head2);
    node* ptr1;
    node* ptr2;
    int dif=0;
    if(l1>l2)
    {
        ptr1=head;
        ptr2=head2;
        dif=l1-l2;
    }
    else
    {
        ptr1=head2;
        ptr2=head;
        dif=l2-l1;
    }
    while(dif)
    {
        ptr1=ptr1->next;
        if(ptr1->next==NULL)
        return -1;
        dif--;
    }
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)
        return ptr1->data;

        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
    
}
void intersect(node* &head,node* &head2,int pos)
{
    node* temp=head;
    pos--;
    while(pos--)
    {
        temp=temp->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp;
}
void display(node* head)
{
    while (head->next!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
    
}
int main()
{
    node* head=NULL;
    insertAtTell(head,1);
    insertAtTell(head,2);
    insertAtTell(head,3);
    insertAtTell(head,4);
    insertAtTell(head,5);
    
    
    node* head2=NULL;
    insertAtTell(head2,10);
    insertAtTell(head2,20);
    intersect(head,head2,1);
    display(head);
    display(head2);
    cout<<intersect_point(head,head2);
    return 0;
}