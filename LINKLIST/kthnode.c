#include <stdio.h>
#include <stdlib.h>
#include "linklistheader.h"

void delkth(struct node **start,int k){
    struct node *p,*q;
    p=*start;
    int i=1;

    while(i<=k){
        if(p!=NULL){
            i=i+1;
            p=p->next;
        }

        else{
            printf("void deletion");
            exit(1);
        }
    }
    q=*start;
    if(p!=NULL){

        while(p->next!=NULL){
            q=q->next;
            p=p->next;
                    }
        DelAft(&q);

    }
    else{
        DelBeg(&(*start));
    }
}
void main(){
    struct node *start;
    start=NULL;
    insbeg(&start,10);
    insbeg(&start,9);
    insbeg(&start,8);
    insbeg(&start,7);
    insbeg(&start,6);
    insbeg(&start,5);
    insbeg(&start,4);
    insbeg(&start,3);
    insbeg(&start,2);
    insbeg(&start,1);
    traverse(start);
    printf("\n");
    delkth(&start,11);
    traverse(start);
    printf("\n");

}
