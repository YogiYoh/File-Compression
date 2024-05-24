#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h> 

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

bool Search(BstNode* root, int data){
    if(root == NULL){
        return false;
    }else if(root->data == data){
        return true; 
    }else if(data <= root->data){
        return Search(root->left, data); 
    }else{
        return Search(root->right, data); 
    }

    return false;
}

int main(){
    BstNode* root  = NULL; // Store address of root Node 
    root = Insert(root, 15); 
    root = Insert(root, 10); 
    root = Insert(root, 20); 
    root = Insert(root, 15); 

    int value = 20;
    bool found = Search(root, value);
    printf("\n%d is %s in the BST.\n", value, found ? "found" : "not found");


}
