#include <stdio.h>

 
void mergesort(int *arr,int l,int mid,int h)
{
    int i, b, k, a, temp[50];
 
    a = l;
    i = l;
    b = mid + 1;
    while ((a <= mid) && (b <= h))
    {
        if (arr[a] <= arr[b])
        {
            temp[i] = arr[a];
            a++;
        }
        else
        {
            temp[i] = arr[b];
            b++;
        }
        i++;
    }
    if (a > mid)
    {
        for (k = b; k <= h; k++)
        {
            temp[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (k = a; k <= mid; k++)
        {
             temp[i] = arr[k];
             i++;
        }
    }
 
    for (k = l; k <= h; k++)
    {
        arr[k] = temp[k];
    }
}
 
void par(int *arr,int l,int h)
{
    int mid;
 
    if(l < h)
    {
        mid = (l + h) / 2;
        par(arr, l, mid);
        par(arr, mid + 1, h);
        mergesort(arr, l, mid, h);
    }
}


int main()
{
    int arr[100];
    int i, n;
 
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
         scanf("%d", &arr[i]);
    }
    par(arr, 0, n - 1);

    for(i = 0;i < n; i++)
    {
         printf("%d ",arr[i]);
    }
 
   return 0;
}