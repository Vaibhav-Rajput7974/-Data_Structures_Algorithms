/* do stack le ge current and next 
current me se data nikalte jaye ge or print karae ge or next me push karte jaye ge
ak bool variable le ge jo direction batye ga
*/
#include<iostream>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
bool IdenticalBst(Node* root1,Node* root2)
{
    //if(root1==NULL)
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    else if(root1==NULL || root2==NULL)
    {
        return false;
    }
    else
    {
        bool con1=root1->data==root2->data;
        bool con2=IdenticalBst(root1->left,root2->left);
        bool con3=IdenticalBst(root1->right,root2->right);

        if(con1 && con2 && con3)
        return true;
        else 
        return false;
    }
}
int main()
{
    Node* root1=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);
    root1->left->left=new Node(4);
    root1->left->right=new Node(5);
    root1->right->left=new Node(6); 

    Node* root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->left=new Node(4);
    root2->left->right=new Node(5);
    root2->right->left=new Node(6);

    cout<<IdenticalBst(root1,root2);
    return 0;
}