#include <stdio.h>
#include <stdlib.h>
int power(int n,int x){
     if(x==0){
        return 1;
    }
    else{
        return n*power(n,x-1);
    }
}
/**************************/
int main()
{
    int n,x;
    printf("enter base");
    scanf("%d",&n);
    printf("enter power");
    scanf("%d",&x);

    printf("%d",power(n,x));
}
