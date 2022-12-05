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
prcd(char a,char b){
    if(a=='^' || a=='*' || a=='/' || a=='%'){
        if(b=='^'){
            return FALSE;
        }
        else{
            return TRUE;
        }
    }
    else{
        if(b=='+' || b=='-'){
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
}

/********************************/
void infixtopre(char infix[]){
    int i=0,p=0;
    char prefix[20];
    char x,symbol;
    initialise();
    strrev(infix);
    while(infix[i]!='\0'){
        symbol=infix[i];
        i++;
        if((symbol>='a' && symbol<='z') ||( symbol>='A' && symbol<='Z')|| (symbol>='1' && symbol<='9') ){
            prefix[p]=symbol;
            p++;
        }
        else{
            while(!isempty() && !prcd(symbol,stacktop())){
                  x=pop();
                  prefix[p]=x;
                  p++;
            }
            push(symbol);
        }
    }
    while(!isempty()){
        x=pop();
        prefix[p]=x;
        p++;
    }
    prefix[p]='\0';
    strrev(prefix);
    printf("%s",prefix);
}
/********************************/

int main(){
    char infix[20];
    gets(infix);
    infixtopre(infix);
}
