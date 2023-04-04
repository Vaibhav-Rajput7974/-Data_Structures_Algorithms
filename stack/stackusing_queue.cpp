#include<iostream>
#include<queue>
using namespace std;
class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    Stack()
    {
        N=0;
    }
    void push(int val)
    {
        q1.push(val);
        N++;
    }
    void pop()
    {
        if(q1.empty())
        {
            cout<<"No element"<<endl;
            return;
        }
        while(q1.size()==1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    int top()
    {
        if(q1.empty())
        {
            cout<<"No element"<<endl;
            return -1;
        }
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int topele=q1.front();
        q2.push(topele);
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        return topele;
    }
    int siz()
    {
        return N;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<s.siz()<<endl;
    cout<<s.top()<<endl;
    return 0;
}