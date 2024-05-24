#include <stdlib.h> 
#include <stdio.h> 


typedef struct Node{
    int data; 
    struct Node *left, *right; 

}BstNode; 

BstNode* createNode(int data){
    BstNode* newNode = (BstNode*)malloc(sizeof(BstNode)); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
}


BstNode* Insert(BstNode* root, int data){
    if(root == NULL){
        root = createNode(data); 
    }else if(data <= root->data){
        root->left = Insert(root->left, data);
    }else{
        root->right = Insert(root->right, data);
    }
    return root;
}


int main(){
    BstNode* root  = NULL; // Store address of root Node 
    root = Insert(root, 15); 
    root = Insert(root, 10); 
    root = Insert(root, 20); 
}
