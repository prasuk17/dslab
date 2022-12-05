#include <stdio.h>
#include <stdlib.h>
int search(int r,int l,int key,int *arr){
    int mid1,mid2;
    while(r>=l){
        mid1=l+(r-l)/3;
        mid2=r-(r-l)/3;
        if(key==arr[mid1]){
            return mid1;
        }
        if(key==arr[mid2]){
            return mid2;
        }
        if(key<arr[mid1]){
            return search(mid1-1,l,key,arr);
        }
        else if(key>arr[mid2]){
            return search(r,mid2+1,key,arr);
        }
        else{
            return search(mid2-1,mid1+1,key,arr);
        }
    }
}
int main()
{
    int *arr,r,l,n,key,i;
    printf("enter no of elements");
    scanf("%d",&n);
    arr=malloc((n)*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter element to be serached\n");
    scanf("%d",&key);
    l=arr[0];
    r=arr[n-1];
    int s=search(r,l,key,arr);
    printf("found at index:%d\n",s);
}
