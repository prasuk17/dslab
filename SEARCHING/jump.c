#include<stdio.h>
#include<math.h>
int min(int a, int b){
    if(b>a)
      return a;
      else
      return b;
}
int jumpsearch(int arr[], int x, int n)
{

    int step = sqrt(n);


    int prev = 0;
    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }


    while (arr[prev] < x)
    {
        prev++;


        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
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

    int s=jumpsearch(arr,key,n);
    printf("found at index:%d\n",s);
}
