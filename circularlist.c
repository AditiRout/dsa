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
    head->link=head;
    ptr=head; 
    for(i=2;i<=n;i++){
        new=(struct node *)malloc(sizeof(struct node));
        printf("enter data of node %d: ",i);
        scanf("%d",&data);
        new->data=data;
        new->link=head;
        ptr->link=new;
        ptr=ptr->link;
    }
    printf("SUCESS\n");
}
void print(){
    struct node *current;
    
        current = head->link;
        printf("DATA IN THE LIST:\n");

        while(current!=head){ 
            printf("Data  %d\n", current->data);

            current = current->link;
        }
}
            
        

void insertAtEnd(int data){
     struct node *last,*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    last=(struct node*)malloc(sizeof(struct node));
    last->data=data;
    last->link=NULL;
    if(head==NULL){
        head=last;
        head->link=head;
    }
    ptr=head;
    while(ptr->link!=head){
        ptr=ptr->link;
    }
    ptr->link=last;
    last->link=head;
}
void insertAtStart(int data){
    struct node *newNode, *current;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->link = head;

        
        current = head;
        while(current->link != head)
        {
            current = current->link;
        }
        current->link = newNode;

        
        head = newNode;
        printf("NODE INSERTED SUCCESSFULLY\n");
    }
    }
void insertAtNode(int d,int new_data){
   struct node *newNode, *current;
    int i;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else if(new_data == 1)
    {
        insertAtStart(d);
    }
    else
    {
        
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = d;

        
         current = head;
        for(i=2; i<=new_data-1; i++)
        {
            current = current->link;
        }

        
        newNode->link = current->link;
        current->link = newNode;

        printf("NODE INSERTED SUCCESSFULLY.\n");
    }

}
void deleteAtEnd(){
    struct node* temp = (struct node*) malloc(sizeof (struct node));
    temp=head->link;
    struct node* prev = (struct node*) malloc(sizeof (struct node));
    prev=NULL;
    while(temp->link!=head) {
        prev=temp;
        temp= temp->link;}
        
    prev->link = head;
    free(temp);


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

void delany(int n){
    struct node*new,*play,*save;
    int k=1;
    new=(struct node*)malloc(sizeof(struct node));
    new=head;
    
    if(n==1){
        deleteFirstNode();
    }
    else {
        
    while((k!=n )){
            k++;
            save=new;
            
            new=new->link;
            }
        save->link=new->link;
        
        }
    
    free(save);
    
}

int main(){
    int t,p;
    scanf("%d",&t);
    createlist(t);
    printf("insert:");
    scanf("%d",&t);
    insertAtStart(t);
    scanf("%d",&t);
    insertAtEnd(t);
    scanf("%d%d",&t,&p);
    insertAtNode(p,t);
    print();
    delany(t);
    print();
    deleteAtEnd();
    print();
    deleteFirstNode();
    print();



}