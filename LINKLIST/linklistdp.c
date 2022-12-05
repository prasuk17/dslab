#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node * next;
};


struct node* getnode(){
    struct node *p;
    p= (struct node*) malloc(sizeof(struct node));
    return p;
}

void insbeg(struct node **start,int x){
    struct node *p;
    p=getnode();
    p->info=x;
    p->next= *start;
    *start=p;

}

void traverse(struct node *start){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->next;
    }
}

void insend(struct node **start,int x){
    struct node*q, *p;
    q=*start;
    while(q->next!=NULL){
        q=q->next;

    }
    p=getnode();
    p->info=x;
    p->next=NULL;
    q->next=p;

}
void insaft(struct node **q, int x){
    struct node *p,*r;
    p=getnode();
    p->info=x;
    r=(*q)->next;  //p->next=q->next;
    p->next=r;     //q->next=p;
    (*q)->next=p;
}
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

int DelBeg(struct node **start){
    if(*start==NULL){
        printf("void deletion");
        exit (1);
    }
    int x;
    struct node *p;
    p=*start;
    x=p->info;
    *start=(*start)->next;
    free(p);
    return x;
}
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
    x=p->info;
    free(p);
    return x;
}
int DelAft(struct node **p){
    struct node *q,*r;
    int x;
    q=(*p)->next;
    r=q->next;
    (*p)->next=r;
    x=q->info;
    free(q);
    return x;
}
void orderinsert(struct node **start,int x){
    struct node *p,*q;
    p=*start;
    q=NULL;
    while(p!=NULL && x>p->info){
        q=p;
        p=p->next;

    }
    if(q==NULL){
        insbeg(start,x);
    }
    else{
        insaft(&q,x);
    }
}


int main(){
    struct node *start;
    struct node *p;
    int n;
    start= NULL;
    insbeg(&start,100);
    insend(&start,200);
    insend(&start,300);
    insend(&start,400);
    insend(&start,500);

    traverse(start);

    p=start;
    for(int i=0; i<2; i++){
        p=p->next;
    }
    insaft(&p, 40);
    printf("\n");
    traverse(start);
    printf("\n%d\n",Countnode(&start));
    int x=DelBeg(&start);
    traverse(start);
    printf("\ndeleted element= %d \n",x);
    x=DelEnd(&start);
    traverse(start);
    printf("\ndeleted element= %d \n",x);
    p=start;
    printf("\nenter node to be dleted\n");
    scanf("%d",&n);
    for(int i=1;i<n-1;i++){
        p=p->next;
    }
    x=DelAft(&p);
    traverse(start);
    printf("\ndeleted element= %d \n",x);
    orderinsert(&start,250);
    traverse(start);


}
