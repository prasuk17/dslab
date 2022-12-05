#include<stdio.h>
#include"linklistheader.h"
#include"mystackpointer.h"
void ReverseInplace(struct node **start){
    struct node *C,*P,*N;
    C = *start;
    P = NULL;
    N = C->next;
    while(C!=NULL){
        C->next = P;
        P = C;
        C = N;
        if(N!=NULL) N = N->next;
    }
    *start = P;
    //traverse(start);
}
void ReverseUsingStack(struct node **start){
    struct node *p,*start2;
    start2=NULL;
    struct stack s;
    initialise(&s);
    p=*start;

    while(p!=NULL){
        push(&s,p->info);
        p=p->next;
    }
    while(!isempty(&s)){
        insend(&start2,pop(&s));
    }
    traverse(start2);
}
void Reverse(struct node **start){
    struct node *p,*q;
    p=*start;
    q=NULL;
    while(p!=NULL){
        insbeg(&q,p->info);
        p=p->next;
    }
    traverse(q);
}
int main(){
    struct node *start;
    start = NULL;
    insend(&start,1);
    insend(&start,2);
    insend(&start,3);
    insend(&start,4);
    insend(&start,5);
    traverse(start);
    printf("\n");
    ReverseInplace(&start);
     traverse(start);
}
