#include <stdio.h>
#include <stdlib.h>
#include "linklistheader.h"
/**************************/
void push(struct node **top,int x){
    insbeg(&(*top),x);
}
/**************************/
int pop(struct node **top){
    int x;
    x=DelBeg(&(*top));
    return x;
}
int main(){
    struct node *top;
    top=NULL;
    int x;
    scanf("%d",&x);
    push(&top,x);
    traverse(top);
    printf("\n");
    scanf("%d",&x);
    push(&top,x);
    traverse(top);
    printf("\n");
    scanf("%d",&x);
    push(&top,x);
    traverse(top);
    printf("\n");
    scanf("%d",&x);
    push(&top,x);
    traverse(top);
    printf("\n");
    x=pop(&top);
    traverse(top);
    printf("\ndeleted element is %d\n",x);
}
