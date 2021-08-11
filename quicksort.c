#include<stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  





int part(int n[],int l,int h){
    int pivot=l, temp=0;
    int i=l;
    int j=h;
    while(i<j){
        while(n[i]<=n[pivot] && i<j){
            i++;
        }
        while(n[j]>=n[pivot]){
            j--;
            if (i > j) {
                break;
            }
        }
        if(i<j){
            swap(&n[i],&n[j]);
        }
        else {
            swap(&n[j], &n[pivot]);
            pivot = j;
        }
    }
//    swap(&n[j],&n[l]);
    return pivot;
}






void quicksort(int n[],int l,int h){
    if(l>=h) {
        return;
    }
    if(l<h){ 
        int p=part(n,l,h);
        quicksort(n,l,p-1);
        quicksort(n,p+1,h);
    }
}

int main(){
    int n[24];
    int count;
    scanf("%d",&count);
    printf("Enter\n");
    for (int i = 0; i < count; i++)
    {
        /* code */scanf("%d",&n[i]);
    }
    quicksort(n,0,count-1);
    for (int i = 0; i < count; i++)
    {
        printf("%d ",n[i]);
        /* code */
    }
    
    return 0;
}