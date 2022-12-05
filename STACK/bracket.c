#include<stdio.h>
#include<stdlib.h>
#include"mystack.h"
//#include<string.h>
int main(){
    char exp[20];
    int i=0;
    initialise();
    gets(exp);

    while(exp[i]!='\0'){
        if(exp[i]=='('){
            push(exp[i]);
        }
        if(exp[i]==')'){
            pop();
        }
        i++;
    }
    if(isempty()){
        printf("true");
    }
    else{
        printf("false");
    }
}
