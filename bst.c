#include<stdlib.h>
#include<stdio.h>
struct node
{
    struct node *left;
    struct node *right;
    int data;
};

void create(struct node ** ptr, int info)
{
    struct node *tmp, *p;
    if(*ptr == NULL)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = info;
        tmp->left = NULL;
        tmp->right = NULL;
        *ptr = tmp;
    }
    else
    {   
        tmp = *ptr;

        p = (struct node *)malloc(sizeof(struct node));

        p->data = info;
        p->left = NULL;
        p->right = NULL;                                    

        while(tmp->left != NULL || tmp->right != NULL)
        {
            if(info < tmp->data)
            {
                if(tmp->left == NULL)
                    break;
                tmp = tmp->left;
            }
            else
            {
                if(tmp->right == NULL)
                    break;
                tmp = tmp->right;
            }
        }
        
        if(info >= tmp->data)
        tmp->right = p;

        if(info < tmp->data)
        tmp->left = p;                                      
    }
}
void inorder(struct node *ptr)
{
    struct node *tmp = ptr;
    if(tmp != NULL)
    {
        inorder(tmp->left);
        printf("%d ", tmp->data);
        inorder(tmp->right);
    }
}
void main()
{
    
    int data;
    struct  node *ptr = NULL;
    
    for(int i = 0 ; i < 7 ; i++)
    {
        scanf("%d", &data);
        create(&ptr, data);
    }

    inorder(ptr);
}