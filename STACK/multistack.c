
#include <string.h>
#define n 10
#define TRUE 1
#define FALSE 0
#define m 2
int item[n];
int t[m];
/*****************/
initialise(){
    for(int i=0;i<m;i++){
        t[i]=((n*i)/m)-1;
    }
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

