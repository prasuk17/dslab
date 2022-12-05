#include <stdio.h>
#include <stdlib.h>

int factorial (int num){
    if (num==1 || num == 0){
        return 1;

    }
    else {
        return (num* factorial(num-1));
    }
}

int main()
{
    int a;
    printf("enter number you want factorial of\n");
    scanf("%d",&a);
    printf("factorial of %d is :\n %d ",a,factorial(a));

    return 0;
}
