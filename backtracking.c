#include<stdio.h>
#include<stdbool.h>
int count;
count=2;
bool check()
{
    int i;
    for(int i=0;i<=5;i++)
    {
        printf("%d\n",i);
        if(i==count)
        {
            count++;
            if(check())
            {
                printf("Ram\n");
            }
        }
    }
    return true;
}
int main()
{
    check();
    printf("sita\n");
    return 0;
}