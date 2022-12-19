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
int countnode(struct node *t){
    if(t==NULL){
        return 0;
    }
    else{
        return 1+countnode(t->left)+countnode(t->right);
    }
}
/*****************************/
int countleaf(struct node *t){
    if(t==NULL){
        return 0;
    }
    else{
        if(((t->left)==NULL) && ((t->right)==NULL)){
            return 1;
        }
        else{
            return countleaf(t->left)+countleaf(t->right);
        }
    }
}
/*****************************/
int countn2(struct node *t){
    if(t==NULL){
        return 0;
    }
    else{
        if(((t->left)==NULL) && ((t->right)==NULL)){
            return 0;
        }
        else{
            if(((t->left)!=NULL)&& ((t->right)!=NULL)){
                return 1+countn2(t->left)+countn2(t->right);
            }
            else{
                return countn2(t->left)+countn2(t->right);
            }
        }
    }
}
/*****************************/
int countn1(struct node *t){
    if(t==NULL){
        return 0;
    }
    else{
        if(((t->left)==NULL) && ((t->right)==NULL)){
            return 0;
        }
        else{
            if(((t->left)!=NULL)&& ((t->right)!=NULL)){
                return countn1(t->left)+countn1(t->right);
            }
            else{
                return 1+countn1(t->left)+countn1(t->right);
            }
        }
    }
}
/*****************************/
int height(struct node *t){
    if(t==NULL){
        return 0;
    }
    else{
        if(((t->left)==NULL)&& ((t->right)==NULL)){
            return 0;
        }
        else{
            return max((height(t->left)),height(t->right))+1;
        }
    }
}
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
    printf("total node %d\n",countnode(root));
    printf("leaf node %d\n",countleaf(root));
    printf("n2 node %d\n",countn2(root));
    printf("n1 node %d\n",countn1(root));
    printf("height %d\n",height(root));
    printf("\n");
    mirror(&root);
    inorderTraversal(root);
    printf("\n");
    return 0;
}
