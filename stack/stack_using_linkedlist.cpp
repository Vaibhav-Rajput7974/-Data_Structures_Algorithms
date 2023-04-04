#include<iostream>
using namespace std;
class node{
    
    public:
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
class stack{
    node* head;
    int N;
    public:
    stack()
    {
        head=NULL;
        N=0;
    }
    void push(int val)
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
        N++;
    }
    void pop()
    {
        if(head==NULL)
        {
            cout<<"no more element"<<endl;
            return;
        }
        node* temp=head;
        if (head->next==NULL)
        {
            delete head;
            head=NULL;
            return;
        }
        
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        node * todel=temp->next;
        temp->next=NULL;
        delete todel;
        N--;
        return;
    }
    int top()
    {
        node* temp=head;
        if(temp==NULL)
        {
            cout<<"no more element"<<endl;
            return -1;
        }
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        return temp->data;
    }
};
int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;  
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    
    return 0;
}