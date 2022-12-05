#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
struct stack{
    int item[STACKSIZE];
    int TOP;
};
/*************************/
struct stack s;
/*****************/
initialise(){
    s.TOP=-1;
}
/********************************/
int isempty(){
    if (s.TOP==-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
/********************************/
push(int x){
    if(s.TOP==STACKSIZE-1){
        printf("stack overflow");
        exit(1);
    }
    s.TOP=s.TOP+1;
    s.item[s.TOP]=x;
}
/********************************/
pop(){
    if (isempty(s)){
        printf("stack underflow");
        exit(1);
    }
    int x=s.item[s.TOP];
    s.TOP=s.TOP-1;
    return x;
}
/********************************/
int stacktop(){
    int x=s.item[s.TOP];
    return x;
}

/********************************/
char c[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E'};
int main()
{
    initialise();
    int n,b;
    printf("enter no\n");
    scanf("%d",&n);
    printf("enter base\n");
    scanf("%d",&b);
    while(n!=0){
        int r=n%b;
        push(r);
        n=n/b;
    }

    while(!isempty()){
        int x=pop();
        printf("%c",c[x]);
    }
}
