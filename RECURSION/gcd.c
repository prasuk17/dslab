#include <stdio.h>
#include <stdlib.h>
int gcd(int a ,int b){
    if(a==b){
        return a;
    }
    else{
        if(a>b){
            gcd(a-b,b);
        }
        else{
            gcd(a,b-a);
        }
    }
}
int main()
{
    int n1,n2;
    printf("enter firdt no");
    scanf("%d",&n1);
    printf("enter second no");
    scanf("%d",&n2);
    printf("%d",gcd(n1,n2));
}


