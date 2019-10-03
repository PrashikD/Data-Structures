#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct Node{
    int key;
    struct Node *left, *right; 
}BSTNode;

BSTNode* newNode(int data);
BSTNode* insert(BSTNode* root, int data);
BSTNode* search(BSTNode* root, int data);
void printInorder(BSTNode* root);
void printPreorder(BSTNode* root);
void printPostorder(BSTNode* root);
void recurprint2D(BSTNode *root, int space);
void TreeSort(int unsorted_array[], int size);
void print2D(BSTNode *root);

int main(){
    int numbers[] = {7, 4, 8, 5, 6, 9, 3, 2, 1 };
    int n = sizeof(numbers)/sizeof(int);
    TreeSort(numbers, n);
    return 1;
}

BSTNode* newNode(int data){
    BSTNode* temp = (BSTNode*)malloc(sizeof(BSTNode));
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

BSTNode* insert(BSTNode* root, int data){
    if(root == NULL){
        return newNode(data);
    }
    if (data < root->key){
        root->left = insert(root->left, data);
    }
    else if (data > root->key){
        root->right = insert(root->right, data);
    }
    return root;
}
BSTNode* search(BSTNode* root, int data){
    if (root == NULL || root->key == data){
        return root;
    }
    if (root->key < data){
        return search(root->right, data);
    }
    return search(root->left, data);
}

void printInorder(BSTNode* root){
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ",root->key);
    printInorder(root->right);
}
void printPreorder(BSTNode* root){
    if (root == NULL) return;
    printf("%d ",root->key);
    printPreorder(root->left);
    printPreorder(root->right);
}
void printPostorder(BSTNode* root){
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ",root->key);
}
void TreeSort(int unsorted_array[], int size){
    int i; 

    BSTNode* head = NULL;     
    for (i = 0; i < size; i++){
        head = insert(head, unsorted_array[i]);
    }
    printInorder(head);
    return;
}

void recurprint2D(BSTNode *root, int space){  
    if (root == NULL){
        return;
    }
    space += 10; 
    
    recurprint2D(root->right, space); 

    printf("\n"); 
    for (int i = 10; i < space; i++){
        printf(" "); 
    }
    printf("%d\n", root->key); 

    recurprint2D(root->left, space); 
} 
void print2D(BSTNode *root){ 
   recurprint2D(root, 0); 
} 
