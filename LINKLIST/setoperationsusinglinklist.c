#include<stdio.h>
#include<stdlib.h>
#include"linklistheader.h"
void merge(struct node **start1, struct node **start2){
    struct node *p,*q,*start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while((p!=NULL && q!=NULL)){
        if((p->info)<(q->info)){
            insend((&start3),p->info);
            p=p->next;
        }
        else{
            insend((&start3),q->info);
            q=q->next;
        }

    }
    while(p!=NULL){
        insend(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL){
        insend(&start3,q->info);
        q=q->next;
    }
    printf("\n");
    traverse(start3);
}
/********************************/
void union1(struct node **start1, struct node **start2){
    struct node *p,*q,*start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while((p!=NULL && q!=NULL)){
        if((p->info)<(q->info)){
            insend((&start3),p->info);
            p=p->next;
        }
        else if((q->info)<(p->info)){
            insend((&start3),q->info);
            q=q->next;
        }
        else{
            insend((&start3),p->info);
            p=p->next;
            q=q->next;
        }

    }
    while(p!=NULL){
        insend(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL){
        insend(&start3,q->info);
        q=q->next;
    }
    printf("\n");
    traverse(start3);
}
/********************************/
void intersection(struct node **start1, struct node **start2){
    struct node *p,*q,*start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while((p!=NULL && q!=NULL)){
        if((p->info)<(q->info)){
            //insend((&start3),p->info);
            p=p->next;
        }
        else if((q->info)<(p->info)){
            //insend((&start3),q->info);
            q=q->next;
        }
        else{
            insend((&start3),p->info);
            p=p->next;
            q=q->next;
        }

    }
    /*while(p!=NULL){
        insend(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL){
        insend(&start3,q->info);
        q=q->next;
    }*/
    printf("\n");
    traverse(start3);
}
/********************************/
void diff(struct node **start1, struct node **start2){
    struct node *p,*q,*start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while((p!=NULL && q!=NULL)){
        if((p->info)<(q->info)){
            insend((&start3),p->info);
            p=p->next;
        }
        else if((q->info)<(p->info)){
            //insend((&start3),q->info);
            q=q->next;
        }
        else{
            //insend((&start3),p->info);
            p=p->next;
            q=q->next;
        }

    }
    while(p!=NULL){
        insend(&start3,p->info);
        p=p->next;
    }

    printf("\n");
    traverse(start3);
}
/********************************/
void symdiff(struct node **start1, struct node **start2){
    struct node *p,*q,*start3;
    start3=NULL;
    p=*start1;
    q=*start2;
    while((p!=NULL && q!=NULL)){
        if((p->info)<(q->info)){
            insend((&start3),p->info);
            p=p->next;
        }
        else if((q->info)<(p->info)){
            insend((&start3),q->info);
            q=q->next;
        }
        else{
            //insend((&start3),p->info);
            p=p->next;
            q=q->next;
        }

    }
    while(p!=NULL){
        insend(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL){
        insend(&start3,q->info);
        q=q->next;
    }

    printf("\n");
    traverse(start3);
}
/********************************/


int main(){
    struct node *start1,*start2;
    int arr1[5]={10,37,25,89,67};
    int arr2[8]={23,89,49,10,76,67,34,25};
    int i=0;
    start1= NULL;
    start2= NULL;
    for(i=0;i<5;i++){
        orderinsert(&start1,arr1[i]);
    }
    for(i=0;i<8;i++){
        orderinsert(&start2,arr2[i]);
    }
    traverse(start1);
    printf("\n");
    traverse(start2);
    merge(&start1,&start2);
    union1(&start1,&start2);
    intersection(&start1,&start2);
    diff(&start1,&start2);
    symdiff(&start1,&start2);
}
