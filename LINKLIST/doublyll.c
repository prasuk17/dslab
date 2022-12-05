struct node{
    int info;
    struct node * next;
    struct node * prev;
};

/********************************/
struct node* getnode(){
    struct node *p;
    p= (struct node*) malloc(sizeof(struct node));
    return p;
}
/********************************/
void insbeg(struct node **dstart,int x){
    struct node *p;
    p=getnode();
    p->info=x;
    p->prev=NULL;
    p->next= *dstart;
    if((*dstart)!=NULL){
        *dstart->prev=p;
    }
    *dstart=p;

}
/********************************/
void traverse(struct node *dstart){
    struct node*p;
    p=dstart;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->next;
    }
}
/********************************/
void insend(struct node **dstart,int x){
    struct node*q, *p;
    p=*dstart;
    q=getnode();
    q->info=x;
    q->next=NULL;
    if(*dstart!=NULL){
        while(p->next=q){
            p=p->next;
        }
        p->next=q;
        q->prev=p;
    }
    else{
        q->prev=NULL;
        *dstart=q;
    }
}
/********************************/
void insaft(struct node **p, int x){
    struct node *q,*r;
    q=getnode();
    q->info=x;
    r=p->next;
    p->next=q;
    q->prev=p;
    q->next=r;
    if(r!=NULL){
        r->prev=q;
    }
}
void insbef(struct node **p, int x){
    struct node *q,*r;
    q=getnode();
    q->info=x;
    p=r->next;
    r->next=q;
    q->next=p;
    if(r!=null){
        q->prev=r;

    }
}
/********************************/
void main(){
}
