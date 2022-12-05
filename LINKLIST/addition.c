#include<stdio.h>
#include<stdlib.h>
#include"linklistheader.h"
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
}
int Addition(struct node **start1,struct node **start2){
    struct node *p,*q,*start3;
    start3=NULL;
    ReverseInplace(start1);
    ReverseInplace(start2);
    p=*start1;
    q=*start2;
    int carry = 0,total,sum;
    while(p!=NULL & q!=NULL){
        total = p->info + q->info + carry;
        sum = total%10;
        carry = total/10;
        p=p->next;
        q=q->next;
        insbeg(&start3,sum);
    }
    while(p!=NULL){
        total = p->info + carry;
        sum = total%10;
        carry = total/10;
        p=p->next;
        insbeg

        (&start3,sum);
    }
    while(q!=NULL){
        total = q->info + carry;
        sum = total%10;
        carry = total/10;
        q=q->next;
        insbeg(&start3,sum);
    }
    if(carry>0){
        insbeg(&start3,sum);
    }
    traverse(start3);
}
int main(){
    struct node *start1,*start2;
    start1  = NULL;
    insend(&start1,1);
    insend(&start1,2);
    insend(&start1,3);
    insend(&start1,3);
    start2 = NULL;
    insend(&start2,1);
    insend(&start2,8);
    insend(&start2,3);
    Addition(&start1,&start2);
}
