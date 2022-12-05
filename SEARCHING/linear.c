#include <stdio.h>
#include <stdlib.h>
void sort(int *arr,int n){
    int i,j,count=1;
    for(i=0;i<n-1 && count==1;i++){
        count=0;
        for(j=0;j<=n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count=1;
            }

        }
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
/**************/
int main()
{
    int *arr,n,i;
    scanf("%d",&n);
    arr= malloc((n)*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
}
