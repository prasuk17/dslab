#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linklistheader.h"
int sum=0;
int rev(int n){
    if(n==0){
        return sum;
    }
    else{
        sum=sum*10+(n%10);
        return rev(n/10);
    }
}
void reverseinplace(struct node **start){
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
int add(struct node **start1,struct node **start2){
    struct node *p,*q,*start3;
    start3=NULL;
    reverseinplace(start1);
    reverseinplace(start2);
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
    start1=NULL;
    start2=NULL;
    int i=0,count=0,a,j;
    char str1[100];
    gets(str1);
    char str2[100];
    gets(str2);
    strrev(str1);
    strrev(str2);

    for(i=0;i<strlen(str1);i++){
        if(count<4){
            //printf("%c",str1[i]);
            a=(a*10)+atoi(str1[i]);
            count++;
        }
        if(count==4){
            //printf("%d",a);
            a=rev(a);
            insend(&start1,a);
            count=0;
            a=0;
        }
    }
    traverse(start1);
}

