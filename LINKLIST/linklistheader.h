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
void insbeg(struct node **start,int x){
    struct node *p;
    p=getnode();
    p->info=x;
    p->next= *start;
    *start=p;

}
/********************************/
void traverse(struct node *start){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->next;
    }
}
/********************************/
void insend(struct node **start,int x){
    struct node*q, *p;
    q=*start;
    if(q==NULL){
        insbeg(start,x);
    }
    else{
        while(q->next!=NULL){
            q=q->next;

        }
        p=getnode();
        p->info=x;
        p->next=NULL;
        q->next=p;
    }

}
/********************************/
void insaft(struct node **q, int x){
    struct node *p,*r;
    p=getnode();
    p->info=x;
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
    x=p->info;
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
    x=p->info;
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
    x=q->info;
    free(q);
    return x;
}
/********************************/
void orderinsert(struct node **start,int x){
    struct node *p,*q;
    p=*start;
    q=NULL;
    while(p!=NULL && x>=p->info){
        q=p;
        p=p->next;

    }
    if(q==NULL){
        insbeg(&(*start),x);
    }
    else{
        insaft(&q,x);
    }
}
/********************************/

void concatenate(struct node **start1, struct node **start2)
{
    struct node *p;
    p= *start1;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next= *start2;
    //return start1;
}
/********************************/
int middle(struct node**start){
    struct node*t,*r;
    t= *start;
    r=(*start);
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
    }
    return t->info;
}
/********************************/
int cycledetection(struct node**start){
    struct node*t,*r;
    t= *start;
    r=(*start);

    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){

            return 1;
        }
    }

    return 0;
}
/********************************/
int cyclelength(struct node**start){
    struct node*t,*r;
    t= *start;
    r=(*start)->next;
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){
            break;
        }
    }
    int c=0;
    do{
        c++;
        t=t->next;
    }while(t!=r);
    return c;
}
/********************************/
int cyclestartpoint(struct node**start){
    struct node*t,*r,*p;
    int c=0;
    t=*start;
    r=*start;
    p=*start;
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){
            p=p->next;
            r=r->next;
            if(r==p){
                return r->info;
            }
        }
    }
    return 0;
}
