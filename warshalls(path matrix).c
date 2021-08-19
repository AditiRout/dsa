//to find path matrix

#include<stdio.h>
#include<stdlib.h>
#define c 4
void printmatrix(int p[][c]){
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}

void warshall(int a[][c]){
    int i,j,k;
    int p[c][c];
    for(i=0;i<c;i++){
        for ( j = 0; j < c; j++)
        {
            if( a[i][j]==0){
                p[i][j]=0;

            }
            else{
                p[i][j]=1;
            }
        }
    }
    for(k=0;k<c;k++){
        for(i=0;i<c;i++){
        for ( j = 0; j < c; j++)
         {
             p[i][j]=p[i][j]||(p[i][k]&&p[k][j]);
         }
        }


    }
    printmatrix(p);

    }
int main(){
    int t;
    scanf("%d",&t);
    int a[t][t];
    printf("enter values of matrix:/n");
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            printf("Enter value for a[%d][%d]:\n", i, j);
            scanf("%d", &a[i][j]);
        }

    }
    warshall(a);
    return 0;
}