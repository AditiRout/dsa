#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) {
struct node* node = (struct node*)malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return (node);
}

struct node *buildTree(int *arr, int low, int high, struct node *n) {
 
   if(low < high) {
       struct node *new_node = newNode(arr[low]);
       n = new_node;
       n->left = buildTree(arr, 2*low+1 , high, n->left);
       n->right = buildTree(arr, 2*low+2 , high, n->right);
       
   }
   return n;
}

void printInorder(struct node *n) {
    if(n != NULL) {
        printInorder(n->left);
        printf("%d ", n->data);
        printInorder(n->right);
        }
}

void printPreOrder(struct node *n) {
    if(n != NULL) {
        printf("%d ", n->data);
        printPreOrder(n->left);
        printPreOrder(n->right);
}
}

void printPostOrder(struct node *n) {
    if(n != NULL) {
        printPostOrder(n->left);
        printPostOrder(n->right);
        printf("%d ", n->data);
}
}

int main() {
    int size=7;
    int arr[7];
    for (size_t i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        
    }
    struct node *root = buildTree(arr, 0, size, root);
    printf("\nPreorder: ");
    printPreOrder(root);
    printf("Inorder: ");
    printInorder(root);
    printf("\nPostorder: ");
    printPostOrder(root);
    return 0;
}
