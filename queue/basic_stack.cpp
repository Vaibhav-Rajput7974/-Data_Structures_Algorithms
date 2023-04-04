#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int> st1;
    stack<int> st2;
    public:
    void push(int x)
    {
        st1.push(x);
    }
    int pop()
    {
        if(st1.empty() && st2.empty())
        {
            cout<<"Queue is empty"<<endl; 
            
        return -1;
        }
        if(st2.empty())
        {
            while(st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int topval=st1.top();
        st1.pop();
        return topval;
    }
    /*int popreccursive()
    {
        if(st1.empty())
        {
            cout<<"Queue is empty"<<endl; 
            
        return -1;
        }
        int x=st1.top();
        st1.pop();
        if(st1.empty())
        {
            return x;
        }
        int item=pop();
        s.push(x);
        return item;
    }*/

};
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    
}