#include <stdio.h>
#include <stdlib.h>
void mergearray(int *a,int m,int *b,int n){
    int *c;
    c=malloc((m+n)*sizeof(int));
    int i=0;
    int j=0;
    int k=0;
    while(i<m && j<n)
        {
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<m){
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<n){
        c[k]=b[j];
        k++;
        j++;
    }
    /*for(i=0;i<m;i++){
        printf("%d ",a[i]);
    }*/
    printf("merge\n");
    for(i=0;i<k;i++){
        printf("%d ",c[i]);
    }
}
/********************/
void arrayunion(int *a,int m,int *b,int n){
    int i=0;
    int j=0;
    int k=0;
    int *c;
    c=malloc((m+n)*sizeof(int));
    while(i<m && j<n)
        {
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            if(b[j]<a[i]){
                c[k]=b[j];
                k++;
                j++;
            }
            else{
                c[k]=a[i];
                i++;
                k++;
                j++;
            }

        }
    }
    while(i<m){
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<n){
        c[k]=b[j];
        k++;
        j++;
    }
    /*for(i=0;i<m;i++){
        printf("%d ",a[i]);
    }*/
    printf("\nunion\n");
    for(i=0;i<k;i++){
        printf("%d ",c[i]);
    }

}
/********************/
void intersection(int *a,int m,int *b,int n){
    int i=0;
    int j=0;
    int k=0;
    int *c;
    c=malloc((m+n)*sizeof(int));
    //printf("\nhi\n");
    while(i<m && j<n)
        {
        if(a[i]<b[j]){
            //c[k]=a[i];
            i++;
            //k++;
        }
        else{
            if(b[j]<a[i]){
                //c[k]=b[j];
                //k++;
                j++;
            }
            else{
                c[k]=a[i];
                i++;
                k++;
                j++;
            }

        }
        //printf("\nhi\n");
    }

    /*while(i<m){
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<n){
        c[k]=b[j];
        k++;
        j++;
    }*/
    /*for(i=0;i<m;i++){
        printf("%d ",a[i]);
    }*/
    printf("\nintersection\n");
    for(i=0;i<k;i++){
        printf("%d ",c[i]);
    }
}
/********************/
void difference(int *a,int m,int *b,int n){
     int i=0;
    int j=0;
    int k=0;
    int *c;
    c=malloc((m+n)*sizeof(int));
    while(i<m && j<n)
        {
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            if(b[j]<a[i]){
                //c[k]=b[j];
                //k++;
                j++;
            }
            else{
               // c[k]=a[i];
                i++;
                //k++;
                j++;
            }

        }
    }
    while(i<m){
        c[k]=a[i];
        k++;
        i++;
    }
    /*while(j<n){
        c[k]=b[j];
        k++;
        j++;
    }*/
    /*for(i=0;i<m;i++){
        printf("%d ",a[i]);
    }*/
    printf("\ndiff\n");
    for(i=0;i<k;i++){
        printf("%d ",c[i]);
    }
}
/********************/
void symdiff(int *a,int m,int *b,int n){
    int i=0;
    int j=0;
    int k=0;
    int *c;
    c=malloc((m+n)*sizeof(int));
    while(i<m && j<n)
        {
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            if(b[j]<a[i]){
                c[k]=b[j];
                k++;
                j++;
            }
            else{
                //c[k]=a[i];
                i++;
                //k++;
                j++;
            }

        }
    }
    while(i<m){
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<n){
        c[k]=b[j];
        k++;
        j++;
    }
    /*for(i=0;i<m;i++){
        printf("%d ",a[i]);
    }*/
    printf("\nsymdiff\n");
    for(i=0;i<k;i++){
        printf("%d ",c[i]);
    }
}
/********************/
int main(){


    int *a;
    int *b;
    int m,n;
    printf("enter no of elements in a");
    scanf("%d",&m);
    a=malloc((m+1)*sizeof(int));
    int i=0;
    printf("enter elements in a");
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    printf("enter no of elements in b");
    scanf("%d",&n);
    b=malloc((n+1)*sizeof(int));
    printf("enter elements in a");
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
   mergearray(a,m,b,n);
    arrayunion(a,m,b,n);
   intersection(a,m,b,n);
   difference(a,m,b,n);
    symdiff(a,m,b,n);
    return 0;
}
