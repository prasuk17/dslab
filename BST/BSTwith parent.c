#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};
struct node *makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void BSTinsert(struct node **T,int x){
    struct node *p,*q,*r;
    p=*T;
    if(*T==NULL){
        *T=makenode(x);
    }
    else{
        while(p!=NULL){
            q=p;
            if(x<p->data){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        r=makenode(x);
        if(x<q->data){
            q->left=r;
            r->parent=q;
        }
        else{
            q->right=r;
            r->parent=q;
        }
    }
}
void inorderBST(struct node *T){
    if(T!=NULL){
        inorderBST(T->left);
        printf("   %d",T->data);
        inorderBST(T->right);
    }
}
int MinBST(struct node *T){
    while(T->left!=NULL){
        T=T->left;
    }
    return T->data;
}
int MaxBST(struct node *T){
    while(T->right!=NULL){
        T=T->right;
    }
    return T->data;
}
struct node *BSTSearch(struct node *T,int x){
    while(T!=NULL){
        if(T->data==x){
            printf("%d\n",T->data);
            return T;
        }
        else{
            if(x<T->data){
                T=T->left;
            }
            else{
                T=T->right;
            }
        }
    }
    return NULL;
}
int main(){
    struct node *root;
    root=NULL;
    int t,x;

    printf("enter no of inputs\n");
    scanf("%d",&t);
    while(t!=0){
        scanf("%d",&x);
        BSTinsert(&root,x);
        t--;
    }
    inorderBST(root);
    printf("\n");
    printf("%d\n",MinBST(root));
    printf("%d\n",MaxBST(root));
    BSTSearch(root,50);

}

