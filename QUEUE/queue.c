#include <stdio.h>
#include <stdlib.h>
#define quequesize 10
#define TRUE 1
#define FALSE 0

struct Queue{
    int item[quequesize];
    int front;
    int rear;
};
/*********************/
struct Queue q;
/*********************/
initialise(struct Queue *q){
    q->front=0;
    q->rear=-1;
}
/**********************/
int isempty(struct Queue *q){
    if((q->rear-q->front+1)==0){
        return TRUE;

    }
    else{
        return FALSE;
    }
}
/***********************/
 void enqueue(struct Queue *q,int x){
    if(q->rear==quequesize-1){
        printf("queue overflow");
        exit(1);
    }
    q->rear=q->rear+1;
    q->item[q->rear]=x;
}
/************************/
int dequeue(struct Queue *q){
    if(isempty(q)){
        printf("queue underflow");
        exit(1);
    }
    int x;
    x=q->item[q->front];
    q->front=q->front+1;
    return x;
}
int main(){
    int y,choice;
    struct Queue myq;
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
