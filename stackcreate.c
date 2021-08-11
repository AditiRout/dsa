#include <stdio.h>
#include <stdlib.h>
#include <limits.h>     // For INT_MIN

#define SIZE 100

// Create a stack with capacity of 100 elements
int stack[SIZE];

// Initially stack is empty 
int top = -1,i;
void push(int element)
{
    // Check stack overflow
    if (top >= SIZE)
    {
        printf("Stack Overflow, can't add more element element to stack.\n");
        return;
    }

    // Increase element count in stack
    top++;

    // Push element in stack
    stack[top] = element;

    printf("Data pushed to stack.\n");
}
int pop()
{
    // Check stack underflow
    if (top < 0)
    {
        printf("Stack is empty.\n");

        // Throw empty stack error/exception
        
        // Hence return minimum integer value as error value
        return INT_MIN;
    }


    // Return stack top and decrease element count in stack
    return stack[top--];
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}
void peep(int x){
    if((top-x+1)<=0){
        printf("\nstack underflow\n");
    }
    else{
        printf("content is: %d\n",stack[top-x+1]);
    }

}


int main()
{
    int choice, data;

    while(1)
    {
        /* Menu */
        printf("------------------------------------\n");
        printf("    STACK IMPLEMENTATION PROGRAM    \n");
        printf("------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4.Peep\n");
        printf("5. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) 
        {
            case 1: 
                printf("Enter data to push into stack: ");
                scanf("%d", &data);
                
                // Push element to stack
                push(data);
                break;

            case 2: 
                data = pop();

                // If stack is not empty
                if (data != INT_MIN)
                    printf("Data => %d\n", data);
                break;

            case 3: 
                display();
                break;

            case 4:
                printf("enter the position :");
                scanf("%d",&data);
                peep(data);
                break;

            case 5: 
                printf("Exiting from app.\n");
                exit(0);
                break;

            default: 
                printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }
    return 0;
}


