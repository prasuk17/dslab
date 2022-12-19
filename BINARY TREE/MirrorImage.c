#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
/*****************************/
struct node* makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
/*****************************/
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
/*****************************/
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

/*****************************/
void mirror(struct node **T){

    struct node *p,*temp;
    if((*T)->left!=NULL || (*T)->right!=NULL){
        mirror(&(*T)->left);
        mirror(&(*T)->right);
        temp=(*T)->left;
        (*T)->left=(*T)->right;
        (*T)->right=temp;
    }
    else{
        return NULL;
    }


}

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

    printf("\n");
    mirror(&root);
    inorderTraversal(root);
    printf("\n");
    return 0;
}
