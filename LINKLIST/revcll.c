#include <stdlib.h>
#include <stdio.h>
#include "mystackpointer.h"
struct node{
    int info;
    struct node * next;
};

/********************************/
struct node* getnode(){
    struct node *p;
    p= (struct node*) malloc(sizeof(struct node));
    return p;
}
/********************************/
void insbeg(struct node **cstart,int x){
    struct node *p;
    p=getnode();
    p->info=x;
    if((*cstart)!=NULL){
        p->next=(*cstart)->next;
        (*cstart)->next=p;
    }
    else{
        (*cstart)=p;
        (*cstart)->next=p;
    }
    //printf("hello");

}
/********************************/
void traverse(struct node *cstart){
    struct node*p;
    p=cstart->next;
    while(p!=cstart){
        printf("%d ", p->info);
        p=p->next;
    }
    printf("%d",p->info);
}
/********************************/
void insend(struct node **cstart,int x){
    struct node *p;
    p=getnode();
    p->info=x;
    if((*cstart)!=NULL){
        p->next=(*cstart)->next;
        (*cstart)->next=p;
        (*cstart)=p;
    }
    else{
        (*cstart)=p;
        (*cstart)->next=p;
    }
}
/********************************/
void insaft(struct node **q, int x){
    struct node *p;

    p=getnode();
    p->info=x;
    p->next=(*q)->next;
    (*q)->next=p;
   // printf("helo");

}
/********************************/
int Countnode(struct node **cstart){
    int c=0;
    struct node *q;
    q=*cstart;
    while(q->next!=q){
        c++;
        q=q->next;
    }
    c++;
    return c;
}
/********************************/
int delbeg(struct node **cstart){
    struct node *p;
    int x;
    p=(*cstart)->next;
    (*cstart)->next=p->next;
    if((*cstart)->next==(*cstart)){
        cstart=NULL;
    }
    x=p->info;
    free(p);
    return x;
}
/********************************/
int delend(struct node **cstart){
    if((*cstart)==NULL){
        printf("void deeltion");
        exit(1);
    }
    int x;
    struct node *p,*q;
    q=(*cstart);
    p=(*cstart)->next;
    while(p->next!=(*cstart)){
        p=p->next;
    }
    p->next=(*cstart)->next;
    (*cstart)=p;
    x=q->info;
    free(q);
    return x;
}
/********************************/
int DelAft(struct node **q){

    struct node *p;
    int x;
    p=(*q)->next;
    (*q)->next=p->next;
    x=p->info;
    free(q);
    return x;
}


/********************************/

struct node* concatenate(struct node **cstart1, struct node **cstart2)
{
    struct node *p,*q;
    p= (*cstart1)->next;
    q= (*cstart2)->next;
    (*cstart1)->next=q;
    (*cstart2)->next=p;
    return(*cstart2);

    //return cstart1;
}
/********************************/
struct node* rev(struct node **cstart){
    struct node *p;
    struct stack s;
    initialise(&s);
    p=(*cstart)->next;
    while(p!=(*cstart)){
        push(&s,p->info);
        p=p->next;
    }
    push(&s,p->info);
    p=(*cstart)->next;
    while(p!=(*cstart)){
        insend(&p,pop(&s));
        p=p->next;
    }
    insend(&p,pop(&s));
    p=p->next;
    return *cstart;

}
/*********************************/
void main(){
    struct node *cstart1,*cstart2,*cstart3,*q;
    cstart1=NULL;
    cstart3=NULL;
    insbeg(&cstart1,10);
    insbeg(&cstart1,20);
    insbeg(&cstart1,30);
    insbeg(&cstart1,40);
    insend(&cstart1,5);
    q=cstart1;
    for(int i=0; i<4; i++){
        q=q->next;
    }
    insaft(&q, 7);
    traverse(cstart1);
    printf("\n");
    cstart3=rev(&cstart1);
    traverse(cstart3);
}

