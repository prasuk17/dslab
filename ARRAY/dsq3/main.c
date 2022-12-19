#include<stdio.h>
int main(){
    int a,n,m;
    int *arr;
    printf("Enter number of elements: ");
    scanf("%d",&a);
    arr = malloc((a+1) * sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to enter: ");
    scanf("%d",&n);
    m=a;
    for(int i=0;i<a;i++){
        if(n<arr[i]){
            =i;
            break;
        }
    }
    for(int i=a;i>=m;i--){
        arr[i]=arr[i-1];
    }
    arr[m]=n;
    for(int i=0;i<a+1;i++){
        printf("%d ",arr[i]);
    }
}
