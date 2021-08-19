//bubble sort
#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int arr[100],t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&arr[i]);
    }
    int a,b;
    for(a=0;a<t-1;a++){
        for(b=0;b<t-a-1;b++){
            if(arr[b]>arr[b+1]){
                swap(&arr[b],&arr[b+1]);
            }
        }
    }
    
    for(a=0;a<t;a++){
        printf("%d ",arr[a]);
        
    }
    return 0;
}

//selection sort
#include<stdio.h>

void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}

int main(){
    int n,arr[100],min;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
    
}
//insertion sort
#include<stdio.h>
#include<math.h>

int main(){
    int n,arr[100],a,b,t;
    scanf("%d",&n);
    for(a=0;a<n;a++){
        scanf("%d",&arr[a]);
    }
    
    for(a=1;a<n;a++){
        t=arr[a];
        b=a-1;
        while((b>=0)&& (arr[b]>t)){
            arr[b+1]=arr[b];
            b=b-1;
        }
        arr[b+1]=t;
    }
    
    for(a=0;a<n;a++){
        printf("%d ",arr[a]);
    }
    
}
