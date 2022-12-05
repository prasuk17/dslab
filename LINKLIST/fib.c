#include <stdlib.h>
#include <stdio.h>
int DAT[100];
int DAT1[101];
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
int maxele(struct node **cstart){
    struct node *p;
    int max=0;
    p=(*cstart)->next;
    while(p!=(*cstart)){
        if((p->info)>max){
            max=p->info;
        }
    }
    return max;

}
/********************************/

int fib(int n){
    if(n==1){
        DAT1[n]=0;
    }
    else if(n==2){
        DAT1[n] = 1;
    }
    else{
        if(DAT1[n]==0){
            DAT1[n] = fib(n-1)+fib(n-2);
        }
    }
    return DAT1[n];
}
/********************************/
void delfib(struct node **cstart){
    struct node *p;
    int max;
    printf("hello\n");
    max=maxele(&(*cstart));
    printf("hello\n");
    for(int i=0;fib(i)<=max;i++){
        DAT[fib(i)]++;
    }
    for(int i=0;i<max;i++){
        printf("%d",DAT[i]);
    }
}
/********************************/


void main(){
    struct node *cstart1,*q;
    cstart1=NULL;
    //cstart3=NULL;
    insbeg(&cstart1,1);
    insbeg(&cstart1,2);
    insbeg(&cstart1,3);
    insbeg(&cstart1,4);
    insend(&cstart1,5);
    insend(&cstart1,7);
    insend(&cstart1,8);
    insend(&cstart1,9);
    insend(&cstart1,10);
    traverse(cstart1);
    printf("\n");
    delfib(&cstart1);
}

