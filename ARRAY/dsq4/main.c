#include<stdio.h>
void main(){
 int a,t=1;
    int *arr;
    printf("Enter number of elements: ");
    scanf("%d",&a);
    arr = malloc((a+1) * sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    int n,m;
    printf("Enter Element to Delete: ");
    scanf("%d",&n);
    for(int i=0;i<a;i++){
        if(n==arr[i]){
            m=i;
            t=1;
            break;
        }
    }
    if(t==1){
        for(int i=m;i<a;i++){
            arr[i]=arr[i+1];
        }

        for(int i=0;i<a-1;i++){
            printf("%d ",arr[i]);
        }
    }
    else{
        printf("Element is not present in array");
    }
}
