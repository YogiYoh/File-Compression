#include <stdlib.h> 
#include <stdio.h> 


typedef struct Node{
    int data; 
    struct Node *left, *right; 

}BstNode; 

BstNode createNode(int data){
    BstNode* newNode = (BstNode*)malloc(sizeof(BstNode)); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
}


int main(){
    BstNode* root  = NULL; // Store address of root Node 
    Insert(root, 15); 
    Insert(root, 10); 
    Insert(root, 20); 
}
