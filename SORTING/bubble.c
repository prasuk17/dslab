#include <stdio.h>
#include <stdlib.h>
void search(int *arr,int n){
    int i,j,search,s,e,mid;
    printf("enter element to be searched");
    scanf("%d",&search);
    s=0;
    e=n-1;
    mid=(s+e)/2;
    while(s<=e&& arr[mid]!=search){
        if(search>arr[mid]){
            s=mid+1;
            mid=(s+e)/2;

        }
        else{
            e=mid-1;
            mid=(s+e)/2;
        }
    }
    if(arr[mid]==search){
        printf("number is found");
    }
    else{
        printf("number is not found");
    }
}
/***************/
int main()
{
    int *arr,i,n;
    printf("size of array\n");
    scanf("%d",&n);
    arr=malloc((n)*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    search(arr,n);
    return 0;
}
