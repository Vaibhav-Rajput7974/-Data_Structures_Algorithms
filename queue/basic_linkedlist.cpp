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
class Queue
{
    node* front;
    node* back;
    public:
    Queue()
    {
        front=NULL;
        back=NULL;
    } 
    void push(int x)
    {
        node* n=new node(x);
        if(front==NULL)
        {
            front=n;
            back=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void pop()
    {
        if(front==NULL)
        {
            cout<<"Queue Under flow";
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;
    }
    int peek()
    {
        if(front==NULL) 
        {
            cout<<"No element";
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if(front==NULL)
        {
            return true;
        }
        false;
    }
};
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    return 0;
}