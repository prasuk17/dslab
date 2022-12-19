#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat1[100][100];
    int mat2[100][100];
    int mat3[100][100];
    int r1=0,r2=0,c1=0,c2=0,i=0,j=0;
    if(r1!=r2 && c1!=c2){
        printf("addition not possible");
    }
    else{
        printf("enter no of rows in matrix 1;\n");
        scanf("%d",&r1);
        printf("enter no of columns in matrix 1;\n");
        scanf("%d",&c1);
        printf("enter no of rows in matrix 2;\n");
        scanf("%d",&r2);
        printf("enter no of columns in matrix 2;\n");
        scanf("%d",&c2);
        printf("enter elements of matrix 1\n");
            for(i=0;i<r1;i++){
                for(j=0;j<c1;j++){
                    scanf("%d",&mat1[i][j]);
                }

            }
            printf("enter elements of matrix 2\n");
            for(i=0;i<r2;i++){
                for(j=0;j<c2;j++){
                    scanf("%d",&mat2[i][j]);
                }

            }
            for(i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    mat3[i][j]=mat1[i][j]+mat2[i][j];
                }
            }
            for(i=0;i<r1;i++){
                for(j=0;j<c2;j++){
                    printf("%d ",mat3[i][j]);
                }
                printf("\n");
            }

        }
}
