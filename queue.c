#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int n = 100;
int queue[100];
int f = -1, r = -1;
void enque(int x)
{
    if (f == 0 && (r + 1) == n)
    {
        printf("queue is overflow\n");
         return;
    }
    if (f == (r + 1))
    {
        printf("queue is overflow\n");
        return;
            }
    /*if(r==n-1){//circular
 r=1;

 }*/
if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
      

    }
    else
    {
        r = r + 1;
      

    }
    queue[r] = x;

  
}

void deque()
{
    int x;
    if (f == -1 || f > r)
    {
        printf("underflow\n");

       
    }
    else
    {
        x = queue[f];
        if (f == r && f != -1)
        {
            f == -1;
            r == -1;

           
        }
         /*else if(f==n-1) //circular
 f=1;
 }*/
 else
        {
            f = f + 1;
           
        }
        printf("value deleted\n");
       
    }
}
void display()
{
    int i, size = 0;

 if (r == -1)

    {
      
    printf("\nEmpty queue\n");
      

    }
  
 else

    {
       printf("\nprinting values .....\n");
      for (i = f; i <= r; i++)

        {
          
         size += 1;
            printf("\n%d\n", queue[i]);
          

        }
       
 printf("size: %d\n", size);
      

    }
  
}

int main()
{
    int c=1;
    while(c!=0){
    int d;
    printf("1.enque\n");
    printf("2.deque\n");
    printf("3.display\n");
    scanf("%d", &c);
  
 switch (c)
    {
      
    case 1 :
        printf("Enter:");
        scanf("%d", &d);
        enque(d);
        break;

    case 2 :
           deque();
           break;
    case 3 :
           display();
        break;
       
    }
    }
    return 0;
}