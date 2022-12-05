
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

