#include<iostream>
#define n 100
using namespace std;
class stack{
    int* arr;
    int top;
    public:
    stack()
    {
        arr=new int[n];
        top=-1; 
    }
    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"Stackoverflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"NO ELemnet"<<endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if(top==-1)
        {
            cout<<"No element"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top==-1;
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    
    return 0;
}