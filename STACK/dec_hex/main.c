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
int main()
{
    initialise();
    int x;
    printf("enter no");
    scanf("%d",&x);
    while(x!=0){
        int rem=x%16;
        push(rem);
        x=x/16;
    }
    while(!isempty()){
        int a=pop();
        if(a>=10){
            printf("%c",65+(a-10));
        }
        else{
            printf("%d",a);
        }

    }



}

