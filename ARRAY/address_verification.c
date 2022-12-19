#include <stdio.h>
#include <stdlib.h>

int main()
{
   int arr[10]={1,2,3,4,5,6,7,8,9,10},i;

    printf("%d\n",arr);
    printf("%u\n",&arr[4]);
    int x=(4-0);
    printf("%d",arr+x);



    /*int arr[4][5]={1,2,3,4,5,6,7,8,9};
    int i=2,j=3;
    printf("%d\n",arr[0]);
    printf("%d\n",&arr[2][3]);
    int x = ((i-0)*(4-0+1)+(j-0));
    printf("%u",arr[0]+x);*/

    /*int arr[3][4][5];
    int i=2,j=0,k=3;
    printf("%u\n",arr[0][0]);
    printf("%u\n",&arr[2][0][3]);
    int x= (((i-0)*(3-0+1)*(4-0+1))+((j-0)*(4-0+1)+(3-0)));
    printf("%u",arr[0][0]+x);*/
}

