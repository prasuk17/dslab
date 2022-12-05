#include <stdio.h>
#include <stdlib.h>
#include "linklistheader.h"
/*******************************/
void enqueue(struct node **front,struct node **rear,int x){
    if(*rear==NULL){
        insbeg(&(*rear),x);
        *front=*rear;
    }
    else{
        insaft(&(*rear),x);
        *rear=(*rear)->next;
    }
}
/*******************************/
int dequeue(struct node **front,struct node **rear){
    int x;
    if(*front==NULL){
        printf("void deletion");
        exit(1);
    }
    else{
    x=DelBeg(&(*front));
        if(*front==NULL){
            *rear=NULL;

        }
    }
    return x;
}
/*******************************/
int main(){
    struct node *front,*rear;
    front=NULL;
    rear=NULL;
    int x;
    scanf("%d",&x);
    enqueue(&front,&rear,x);
    traverse(front);
    printf("\n");
    scanf("%d",&x);
    enqueue(&front,&rear,x);
    traverse(front);
    printf("\n");
    scanf("%d",&x);
    enqueue(&front,&rear,x);
    traverse(front);
    printf("\n");
    scanf("%d",&x);
    enqueue(&front,&rear,x);
    traverse(front);
    printf("\n");
    x=dequeue(&front,&rear);
    traverse(front);
    printf("\ndeleted element is %d\n",x);
}
