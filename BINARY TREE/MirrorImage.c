
#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node *left;
    struct Node *right;
};
struct Node* MakeNode(char x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void PreorderTraversal(struct Node *T){
    if(T!=NULL){
        printf("%c ",T->data);
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
    }
}

void inorderTraversal(struct Node *T){
    if(T!=NULL){
        PreorderTraversal(T->left);
        printf("%c ",T->data);
        PreorderTraversal(T->right);
    }
}
void postorderTraversal(struct Node *T){
    if(T!=NULL){
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
        printf("%c ",T->data);
    }
}
void mirror(struct node **T){
    struct node *temp;
    if((*T)->left!=NULL) && (*T)->right!=NULL) ){
        temp=*T->left->data;
        *T->left->data=*T->right->data;
        *T->right->data=temp;
        mirror(*T->left);
        mirror(*T->right);
    }
    else{
        if(*T->left==NULL){
            *T->left->data=*T->right->data;
            *T->right=NULL;
            mirror(*T->left);
        }
        else{
            *T->right->data=*T->left->data;
            *T->left=NULL;
            mirror(*T->right);
        }
    }
}
int main(){
    struct Node *root=NULL;
    root=MakeNode('A');
    root->left=MakeNode('B');
    root->right=MakeNode('C');
    root->right->left=MakeNode('E');
    root->right->right=MakeNode('F');
    root->right->left->left=MakeNode('G');
    root->right->left->left->right=MakeNode('H');
    PreorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    mirror(root);
    inorderTraversal(root);
    printf("\n");
    return 0;
}
