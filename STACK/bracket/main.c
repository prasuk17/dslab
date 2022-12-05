#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
struct stack{
    char item[STACKSIZE];
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
push(char x){
    if(s.TOP==STACKSIZE-1){
        printf("stack overflow");
        exit(1);
    }
    s.TOP=s.TOP+1;
    s.item[s.TOP]=x;
}
/********************************/
char pop(){
    if (isempty(s)){
        printf("stack underflow");
        exit(1);
    }
    char x=s.item[s.TOP];
    s.TOP=s.TOP-1;
    return x;
}
/********************************/
char stacktop(){
    char x=s.item[s.TOP];
    return x;
}

/********************************/
