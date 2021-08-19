#include<stdio.h>
#include<stdlib.h>

int main(){
    int t;
    scanf("%d",&t);
    int a[t][t];
    int p[t][t];
    printf("Enter elements of A\n");
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){

            scanf("%d",&a[i][j]);
            if(a[i][j]==0){
                p[i][j]=10000000;
            }
            else{
                p[i][j]=a[i][j];
            }
        }
    }
    for(int k=0;k<t;k++){
        for(int I=0;I<t;I++){
            for(int J=0;J<t;J++){
                p[I][J]=((p[I][J]>=(p[I][k]+p[k][J]))?(p[I][k]+p[k][J]):p[I][J]);
            }
        }
    }
    printf("required matrix is:\n");
    for(int h=0;h<t;h++){
        for(int g=0;g<t;g++){
            printf("%d ",p[h][g]);
        }
        printf("\n");
    }
    return 0;
}