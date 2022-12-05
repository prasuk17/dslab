#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node * next;
};

/********************************/
struct node* getnode(){
    struct node *p;
    p= (struct node*) malloc(sizeof(struct node));
    return p;
}
/********************************/
void insbeg(struct node **start,int x,int y){
    struct node *p;
    p=getnode();
    p->coeff=x;
    p->exp=y;
    p->next= *start;
    *start=p;

}
/********************************/
void traverse(struct node *start){
    struct node*p;
    p=start;
    while(p!=NULL){
        if(p->next==NULL){
                printf("%dx^%d", p->coeff,p->exp);
                p=p->next;
           }
        else{
            printf("%dx^%d+", p->coeff,p->exp);
            p=p->next;
        }
    }
}
/********************************/
void insend(struct node **start,int x,int y ){
    struct node*q, *p;
    q=*start;
    if(q==NULL){
        insbeg(start,x,y);
    }
    else{
        while(q->next!=NULL){
            q=q->next;

        }
        p=getnode();
        p->coeff=x;
        p->exp=y;
        p->next=NULL;
        q->next=p;
    }

}
/********************************/
void insaft(struct node **q, int x,int y){
    struct node *p,*r;
    p=getnode();
    p->coeff=x;
    p->exp=y;
    r=(*q)->next;  //p->next=q->next;
    p->next=r;     //q->next=p;
    (*q)->next=p;
}
/********************************/
int Countnode(struct node **start){
    int c=0;
    struct node *q;
    q=*start;
    while(q!=NULL){
        c++;
        q=q->next;
    }
    return c;
}
/********************************/
int DelBeg(struct node **start){
    if(*start==NULL){
        printf("void deletion");
        exit (1);
    }
    int x;
    struct node *p;
    p=*start;
    x=p->coeff;
    *start=(*start)->next;
    free(p);
    return x;
}
/********************************/
int DelEnd(struct node **start){
    int x;
    struct node *p,*q;
    p=*start;
    q=NULL;
    while(p->next!=NULL){
        q=p;
        p=p->next;

    }
    q->next=NULL;
    x=p->coeff;
    free(p);
    return x;
}
/********************************/
int DelAft(struct node **p){
    struct node *q,*r;
    int x;
    q=(*p)->next;
    r=q->next;
    (*p)->next=r;
    x=q->coeff;
    free(q);
    return x;
}
/********************************/
void orderinsert(struct node **start,int x,int y){
    struct node *p,*q;
    p=*start;
    q=NULL;
    while(p!=NULL && y>=p->exp){
        q=p;
        p=p->next;

    }
    if(q==NULL){
        insbeg(&(*start),x,y);
    }
    else{
        insaft(&q,x,y);
    }
}
/********************************/
void polyadd(struct node **poly1,struct node **poly2){
    struct node *poly3,*p,*q;
    poly3=NULL;
    p=*poly1;
    q=*poly2;
    while(p!=NULL && q!=NULL){
        if((p->exp)==(q->exp)){
            insend(&poly3,((p->coeff)+(q->coeff)),p->exp);
            p=p->next;
            q=q->next;
        }
        else{
            if((p->exp)>(q->exp)){
                insend(&poly3,p->coeff,p->exp);
                p=p->next;
            }
            else{
                insend(&poly3,q->coeff,q->exp);
                q=q->next;
            }
        }
    }
    while(p!=NULL){
        insend(&poly3,p->coeff,p->exp);
        p=p->next;
    }
    while(q!=NULL){
        insend(&poly3,q->coeff,q->exp);
        q=q->next;

    }
    traverse(poly3);
}
/****************************/
void polydiff(struct node **poly1,struct node **poly2){
    struct node *q;
    q=*poly2;
    while(q!=NULL){
        q->coeff=-(q->coeff);
        q=q->next;
    }
    polyadd(poly1,poly2);
}
/*******************************/
void polymul(struct node **poly1,struct node **poly2){
    struct node *poly3,*p,*q;
    poly3=NULL;
    p=*poly1;
    q=*poly2;
    while(q!=NULL){
        p=poly1;
        while(p!=NULL){
            orderinsert(&poly3,(p->coeff)*(q->coeff),(p->exp)+(q->exp));
            p=p->next;
        }
        q=q->next;
    }
    p=poly3;
    while((p->next)!=NULL){
        if((p->exp)==(p->next->exp)){
            p->coeff=(p->coeff)+(p->next->coeff);
            DelAft(p);
        }
        else{
            p=p->next;
        }
    }
    traverse(poly3);
}
void main(){
    struct node *poly1,*poly2;
    poly1=NULL;
    poly2=NULL;
    insbeg(&poly1,2,0);
    insbeg(&poly1,3,1);
    insbeg(&poly1,6,2);
    insend(&poly1,5,0);
    insbeg(&poly1,8,4);
    orderinsert(&poly1,4,3);
    traverse(poly1);
    printf("\n\n");
    insbeg(&poly2,5,0);
    insbeg(&poly2,4,1);
    insbeg(&poly2,8,2);
    insend(&poly2,5,0);
    insbeg(&poly2,10,4);
    insaft(&poly2,6,3);
    traverse(poly2);
    printf("\n\n");
    polyadd(&poly1,&poly2);
    printf("\n\n");
    polydiff(&poly1,&poly2);
    printf("\n\n");
    polymul(&poly1,&poly2);
}
