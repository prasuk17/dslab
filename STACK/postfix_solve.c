#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
#include <math.h>
struct stack{
    int item[STACKSIZE];
    int TOP;
};
/*************************/
struct stack s;
/*****************/
void initialise(){
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
int evaluate(int a, int b, char op ){
    switch(op){
        case '+':return(a+b);
        case '-': return (a-b);
        case '*': return (a*b);
        case '/': return (a/b);
        case '%': return (a%b);
        case '^': return (pow(a,b));

    }
}
/********************************/
int main()
{
    int x,i=0,val,b,a;
    char ps[20];
    char symb;
    initialise();
    scanf("%s",&ps);
    while(ps[i]!='\0'){
        symb=ps[i];
        if(symb>='0' && symb <='9'){
            push(symb-48);
        }
        else{
            b=pop();
            a=pop();
            val=evaluate(a,b,symb);
            push(val);
        }
        i++;
    }
    x=pop();
    printf("%d",x);
    return 0;

}
