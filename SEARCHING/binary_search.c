#include <stdio.h>
#include <stdlib.h>
int bs(int *arr, int low,int high,int key){
    if(low<high){
        int mid;
        mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else{
            if(key<arr[mid]){
                bs(arr,low,mid-1,key);
            }
            else{
                bs(arr,mid+1,high,key);
            }
        }
    }
}
int main()
{
    int *arr,n,i ,low,high,key;
    printf("enter no of elements in array");
    scanf("%d",&n);
    arr=malloc((n)*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nenter no to be searched");
    scanf("%d",&key);
    low=0;
    high=n-1;

    printf("\n\n");
    printf("%d",bs(arr,low,high,key));


}
