#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head;
void count(){
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    int c=0;
    ptr=head;
    while(ptr!=NULL){
        c+=1;
        ptr=ptr->link;
    }
    printf("count is %d: ",c);
}
void createlist(int n){
    struct node *new,*ptr;
    head=(struct node *)malloc(sizeof(struct node));
    ptr=(struct node *)malloc(sizeof(struct node));
    int data,i,t;
    printf("enter for 1: ");
    scanf("%d", &t);
    head->data=t;
    head->link=NULL;
    ptr=head; 
    for(i=2;i<=n;i++){
        new=(struct node *)malloc(sizeof(struct node));
        printf("enter data of node %d: ",i);
        scanf("%d",&data);
        new->data=data;
        new->link=NULL;
        ptr->link=new;
        ptr=ptr->link;
    }
    printf("SUCESS\n");
}
void print(){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}

void deleteFirstNode()
{
    struct node *del;
    del = head;
    head = head->link;
    printf("\nData deleted=%d\n",del->data);
    free(del);
    printf("Data from first node deleted\n");
}
void deleteLastNode(){
    struct node *toDelete, *secondLastNode;
    toDelete=head;
    secondLastNode=head;
    while(toDelete->link!=NULL)
    {
        secondLastNode=toDelete;
        toDelete=toDelete->link;
        }
    if(toDelete==head)
    {
        head=NULL;
        }
        else
        {
    secondLastNode->link = NULL;
            }
     free(toDelete);
    printf("Data from last node deleted\n");
}

void delany(int n){
    struct node*new,*play,*save;
    int k=0;
    new=(struct node*)malloc(sizeof(struct node));
    new=head;
    
    if(n==1){
        deleteFirstNode();
    }
    else {
        
    while((k!=n )&&(new!=NULL)){
            k++;
            save=play;
            play=new;
            new=new->link;
            }
        save->link=new;
        
        }
    
    free(play);
    
}

void main(){
    
    int n;
    printf("enter: ");
    scanf("%d",&n);
    createlist(n);
    count();
    print();
    deleteFirstNode();
    deleteLastNode();
    print();
    printf("enter:");
    scanf("%d",&n);
    delany(n);
    print();
}