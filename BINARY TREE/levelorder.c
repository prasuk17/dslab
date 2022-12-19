#include <stdio.h>
#include <stdlib.h>
# define TRUE 1
# define FALSE 0
struct node *rear,*front;
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};
struct node* makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->next=NULL;
    return p;
}
initialise(){
    rear=NULL;
    front=NULL;
}
enqueue(struct node *p){
    if(rear!=NULL){
        rear->next=p;

    }
    else{
        front=p;
    }
    rear=p;

}
 struct node *dequeue(){
    struct node *p;
    p=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    return p;
}
isempty(){
    if(front==NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }

}
void levelorder(struct node *t){
    struct node *p;
    initialise();
    enqueue(t);
    while(!isempty()){
        p=dequeue();
        printf("\t%d",p->data);
        if(p->left!=NULL){
            enqueue(p->left);
        }
        if(p->right!=NULL){
            enqueue(p->right);
        }
    }
}

void createtree(struct node **t){
    int x,choice;
    struct node *p;
    printf("whether left of %d exist?(1/0)\n",(*t)->data);
    scanf("%d",&choice);
    if(choice==1){
        printf("\nenter the data of left of %d\n",(*t)->data);
        scanf("%d",&x);
        p=makenode(x);
        (*t)->left=p;
        createtree(&p);
    }
    printf("\nwhether right of %d exist?(1/0)\n",(*t)->data);
    scanf("%d",&choice);
    if(choice==1){
        printf("\nenter the data of right of %d\n",(*t)->data);
        scanf("%d",&x);
        p=makenode(x);
        (*t)->right=p;
        createtree(&p);
    }

}
/*****************************/
void PreorderTraversal(struct node *T){
    if(T!=NULL){
        printf("%d ",T->data);
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
    }
}
/*****************************/
void inorderTraversal(struct node *T){
    if(T!=NULL){
        inorderTraversal(T->left);
        printf("%d ",T->data);
        inorderTraversal(T->right);
    }
}
/*****************************/
void postorderTraversal(struct node *T){
    if(T!=NULL){
        postorderTraversal(T->left);
        postorderTraversal(T->right);
        printf("%d ",T->data);
    }
}
/*****************************/
int main(){
    struct node *root=NULL;
    int x;
    printf("enter data of root node\n");
    scanf("%d",&x);
    root=makenode(x);
    createtree(&root);
    PreorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    levelorder(root);
}
