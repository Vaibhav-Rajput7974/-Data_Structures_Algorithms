/* Possible BST for given node are equall to catalan number of that node 
*/
#include<iostream>
#include<vector>
using namespace std;
struct Node
{
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
void prtpreorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"   ";
    prtpreorder(root->left);
    prtpreorder(root->right);
}
vector<Node*> possibleBST(int start,int end)
{
    vector<Node*> tree;
    if(start>end)
    {
        tree.push_back(NULL);
        return tree;
    }
    for(int i=start;i<=end;i++)
    {
        vector<Node*> leftsubtree=possibleBST(start,i-1);
        vector<Node*> rightsubtree=possibleBST(i+1,end);

        for(int j=0;j<leftsubtree.size();j++)
        {
            Node* left=leftsubtree[j];
            for(int k=0;k<rightsubtree.size();k++)
            {
                Node* right=rightsubtree[k];
                Node* root=new Node(i);

                root->left=left;
                root->right=right;

                tree.push_back(root);
            }
        }
    }
    return tree;
}
int main()
{
    vector<Node*> root=possibleBST(1,3);
    for(int i=0;i<root.size();i++)
    {
        prtpreorder(root[i]);
        cout<<endl;
    }
    return 0;
}