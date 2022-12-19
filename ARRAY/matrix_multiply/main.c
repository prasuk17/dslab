#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int i,j,k,r1,r2,c1,c2,a[10][10],b[10][10],mul[10][10];
    printf("enter no of rows and column of 1st matrix");
    scanf("%d%d",&r1,&c1);
    printf("enter no of rows and column of 2nd matrix");
    scanf("%d%d",&r2,&c2);
    printf("enter elements of 1st matrix");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
           // mat1[i][j]=0;
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            printf("%d\t",&a[i][j]);
        }
        printf("\n");
    }
    printf("enter elements of 2nd matrix");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            printf("%d\t",&b[i][j]);
        }
        printf("\n");
    }
    if(r2==c1){
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                mul[i][j]=0;
                for(k=0;k<r2;k++){
                    mul[i][j]=mul[i][j]+(a[i][k]*b[k][j]);
                }
            }
        }
    }
    printf(" matrix=");
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            printf("%d\t",&mul[i][j]);
        }
        printf("\n");
    }


    return 0;
}
