#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

typedef struct Node{
    int key;
    bool color;    // true for RED, false for BLACK
    struct Node *left, *right; 
}RBTNode;

RBTNode* newNode(int data);
RBTNode* insert(RBTNode* root, int data);
RBTNode* search(RBTNode* root, int data);

void recurprint2D(RBTNode *root, int space);
void print2D(RBTNode *root);

int main(){
    int numbers[] = {};
    int n = sizeof(numbers)/sizeof(int);
    int i; RBTNode* head;
    for (i = 0; i < n; i++){
        head = insert(head, numbers[i]);
    }
    print2D(head);
    return 1;
}

RBTNode* newNode(int data){
    RBTNode* temp = (RBTNode*)malloc(sizeof(RBTNode));
    temp->key = data;
    temp->left = temp->right = NULL;
    temp->color = true;         // intially set the color to be RED
    return temp;
}

RBTNode* insert(RBTNode* root, int data){
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
RBTNode* search(RBTNode* root, int data){
    if (root == NULL || root->key == data){
        return root;
    }
    if (root->key < data){
        return search(root->right, data);
    }
    return search(root->left, data);
}

void recurprint2D(RBTNode *root, int space){  
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
void print2D(RBTNode *root){ 
   recurprint2DUtil(root, 0); 
} 
