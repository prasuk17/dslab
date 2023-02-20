#include<stdio.h>
#include<stdlib.h>
int main(){
    int r,c;
    int **arr1;
    int *ans;
    int elem;
    printf("enter no of rows\n");
    scanf("%d",&r);
    printf("\nenter no of colums\n");
    scanf("%d",&c);
    arr1=malloc(r*sizeof(int*));
    for(int i=0;i<c;i++){
        arr1[i]=malloc(c*sizeof(int));
    }
    printf("\n enter elemets\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    elem=((r*(r+1))/2);
    ans=malloc(elem*sizeof(int));
    for(int i=0;i<r;i++){
        for(int j=0;j<=i;j++){
            int l=(i*(i+1)/2)+j+1;
            ans[l-1]=arr1[i][j];
        }
    }
    for(int i=0;i<elem;i++){
        printf("%d ",ans[i]);
    }
}
