#include<stdio.h>
int main(){
    int *arr,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
