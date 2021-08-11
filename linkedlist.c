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
void insertatend(int t){
    struct node *last,*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    last=(struct node*)malloc(sizeof(struct node));
    last->data=t;
    last->link=NULL;
    if(head==NULL){
        head=last;
    }
    ptr=head;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=last;
}

void insertNodeAtStart(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->link = head; 

        head = newNode;         
    }
}

void insertat(int n,int data){
    struct node*new,*ptr,*save;
    int k=1;
    ptr=head;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    if(new == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else{
        while(k!=n){
            k++;
            save=ptr;
            ptr=ptr->link;
            

        }
        save->link=new;
        new->link=ptr;
        

    }

}
void main(){
    int n,p;
    printf("enter: ");
    scanf("%d",&n);
    createlist(n);
    count();
    print();
    printf("enter for end: ");
    scanf("%d",&n);
    insertatend(n);
    printf("enter for start: ");
    scanf("%d",&n);
    print();
    insertNodeAtStart(n);
    print();
    printf("enter for n and p : ");
    scanf("%d",&n);
    scanf("%d",&p);
    insertat(n,p);
    print();
    count();
}
