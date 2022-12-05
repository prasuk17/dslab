#include <stdio.h>
#include <stdlib.h>
void toh(int n,char s,char m, char d){
    if(n==1){
        printf("%c --> %c\n",s,d);
    }
    else{
        toh(n-1,s,d,m);
        printf("%c --> %c\n",s,d);
        toh(n-1,m,s,d);
    }
}
int main()
{
   int n,s,d,m;
   printf("enter no of rings");
   scanf("%d",&n);
   toh(n,'s','m','d');

}

