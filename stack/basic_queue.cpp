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
    void push(int x)
    {
        q2.push(x);
        N++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop()
    {
        q1.pop();
        N--;
    }
    int top()
    {
        return q1.front();
    }
    int size()
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
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    return 0;
}