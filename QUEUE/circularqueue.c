
#include <stdio.h>
#include <stdlib.h>
#define quequesize 10
#define TRUE 1
#define FALSE 0

struct Cqueue{
    int item[quequesize];
    int front;
    int rear;
};
/*********************/
struct Cqueue cq;
/*********************/
initialise(struct Cqueue *cq){
    cq->front=quequesize-1;
    cq->rear=quequesize-1;
}
/**********************/
int isempty(struct Cqueue *cq){
    if((cq->rear==cq->front)){
        return TRUE;

    }
    else{
        return FALSE;
    }
}
/***********************/
 void enqueue(struct Cqueue *cq,int x){
    if((cq->rear+1)%quequesize==cq->front){
        printf("queue overflow");
        exit(1);
    }
    cq->rear=(cq->rear+1)%quequesize;
    cq->item[cq->rear]=x;
}
/************************/
int dequeue(struct Cqueue *cq){
    if(isempty(cq)){
        printf("queue underflow");
        exit(1);
    }
    int x;
    cq->front=(cq->front+1)%quequesize;
    x=cq->item[cq->front];
    return x;
}
int main(){
    int y,choice;
    struct Cqueue myq;
    initialise(&myq);
    while(TRUE){
    printf("enter 1 to insert\n");
    printf("enter 2 to remove element\n");
    printf("enter 3 to exit\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("enter element to be entered\n");
            scanf("%d",&y);
            enqueue(&myq,y );
            break;
        case 2:
            y=dequeue(&myq);
            printf("deleted element=%d\n",y);
            break;
        case 3:
            exit(1);

    }
    }

}
