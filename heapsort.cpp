#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void swap(int *a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(int *arr,int n,int i){
    int small=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n){
        small=(arr[l]<arr[small])?l:small;
    }
    if(r<n){
         small=(arr[r]<arr[small])?l:small;

    }
    if(small!=i){
        swap(&arr[i],&arr[small]);
        heapify(arr,n,small);
    }
}

void heapsort(int *arr,int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);

    }
}

int main() 
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}
