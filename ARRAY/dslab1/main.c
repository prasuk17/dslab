#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int n,sum=0,max=-324242,min=999999;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }*/
    //sum
    /*for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    printf("%d",sum);*/


    //partial
   /* int arr[4]={1};
    for(int i=0;i<4;i++){
        printf("%d",arr[i]);
    }*/


    /*max
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            max=arr[i];
        }
    }
    printf("%d",max);*/


    /*minnn
    int i=0;
    min=arr[i];
    for(i=0;i<n-1;i++){

        if(min>arr[i+1]){
            min=arr[i];
        }
    }
    printf("%d",min);*/


   /* if(n%2==0){
        printf("%d ",arr[n/2]);
        printf("%d",arr[(n/2)-1]);
    }
    else{
        printf("%d",arr[(n/2)]);
    }*/

    //rverse
    int i=0,j=n-1;
    for(i,j;i<j;i++,j--){
        int t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }



    /*insert
    int arr[100],n;
    scanf("%d",&n);
    //int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter element to be added");
    int no;
    scanf("%d",&no);
    printf("enter location where element is to be added");
    int loc;
    scanf("%d",&loc);
    int i;
    for(i=n-1;i>=loc-1;i--){
        arr[i+1]=arr[i];
    }
    arr[loc-1]=no;

    for(int i=0;i<n+1;i++){
        printf("%d",arr[i]);
    }*/
    /*int arr[100],n;
    scanf("%d",&n);
    //int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter element to be deleted");
    int no;
    scanf("%d",&no);
    int idx;
    for(int i=0;i<n;i++){
        if(arr[i]==no){
            idx=i;
            break;
        }
    }
    for(int i=idx;i<n-1;i++){
        arr[idx]=arr[i];
    }
    for(int i=0;i<n-1;i++){
        printf("%d",arr[i]);
    }*/


}
