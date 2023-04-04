#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr,n);
    cin.ignore();
    int length=0;
    int maxlength=0;
    int i=0;
    int st=0,maxst=9;
    while(1)
    {
        if(arr[i]== ' ' || arr[i]=='\0')
        {
            if(maxlength<length)
            {
                maxlength=length;
                maxst=st;                
            }
            st=i+1;
            length=0;
        }
        else
        length++;
        
        if(arr[i]=='\0')
        break;

        i++;
    }
    cout<<maxlength<<endl;
    for(int i=0;i<maxlength;i++)
    cout<<arr[i+maxst];
    return 0;
}