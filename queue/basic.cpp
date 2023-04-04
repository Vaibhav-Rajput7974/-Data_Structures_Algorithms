#include<iostream>
#define n 20
using namespace std;
class Queue{
    int* arr;
    int front;
    int back;
    public:
    Queue()
    {
        arr=new int[n];
        front=-1;
        back=-1;
    }
    void push(int x)
    {
        if(back==n-1)
        {
            cout<<"Queue overflow";
            return;
        }
        back++;
        arr[back]=x;
        if(front==-1)
        {
            front++;
        }
    }
    void pop()
    {
        if(front==-1 && front>back)
        {
            cout<<"No element"<<endl;
            return;
        }
        front++;
    }
    int peek()
    {
        if(front==-1 && front>back)
        {
            cout<<"No element"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if(front==-1 && front>back)
        {
            return true;
        }
        return false;
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
    cout<<q.peek();
    return 0; 
}