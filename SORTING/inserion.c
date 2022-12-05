#include <stdio.h>
#include <stdlib.h>
void sort(int *arr,int n){
    int i,j,x;
    for(i=1;i<n;i++){
        x=arr[i];
        j=i-1;
        while(arr[j]>x){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=x;
    }
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
/***********************/
int main()
{
    int *arr,n,i;
    printf("enter no of elements in array");
    scanf("%d",&n);
    arr=malloc((n)*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n\n");
    sort(arr,n);

}
