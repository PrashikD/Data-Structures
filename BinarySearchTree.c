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

void recurprint2D(BSTNode *root, int space);
void print2D(BSTNode *root);

int main(){
    int numbers[] = {};
    int n = sizeof(numbers)/sizeof(int);
    int i; BSTNode* head;
    for (i = 0; i < n; i++){
        head = insert(head, numbers[i]);
    }
    print2D(head);
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
   recurprint2DUtil(root, 0); 
} 
