#include<stdio.h>
int DAT[101];
int fib(int n)
{
    if(n==1)
        DAT[n]= 0;
    else
        if(n==2)
            DAT[n]= 1;
        else
        {
            if(DAT[n]==0)
               DAT[n]= (fib(n-1)+fib(n-2));
        }
    return DAT[n];
}
/************/
int main()
{
    int i,f,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        f=fib(i);
        printf("  %d",f);
    }
}
