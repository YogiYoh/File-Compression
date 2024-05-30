#include <stdlib.h> 
#include <stdio.h> 


#define DEFAULT_CAPACITY 7


typedef struct Node{
    char* value; 
    int size; 
    int capacity;

}BinHeap;

BinHeap* defaultNode(){
    BinHeap* node = (BinHeap*)(malloc)(sizeof(BinHeap)); 
    node->value = (char*)(malloc)(DEFAULT_CAPACITY * sizeof(char)); 

    node->capacity = DEFAULT_CAPACITY; 
    node->size = 0;

    return node; 
}

BinHeap* createNode(int capacity){
    BinHeap* node = (BinHeap*)(malloc)(sizeof(BinHeap)); 
    node->value = (char*)(malloc)(capacity * sizeof(char)); 

    node->capacity = capacity; 
    node->size = 0;

    return node; 
}

void resize(BinHeap* node, int new_capacity){
    if(node->capacity < new_capacity){
        char* temp = (char*)(malloc)(new_capacity * sizeof(char)); 
        for(int i = 0; i < node->capacity; i++){
            temp[i] = node->value[i]; 
        }

        char* old = node->value; 
        node->value = temp;
        node->capacity = new_capacity; 
        free(old);
    }
}

char getParentNode(int index, char* value){
    int parent = index / 2; 
    if(parent != 0){
        return value[parent]; 
    }else{
        return findMax(value); 
    }
}

char findMax(char* value){
    return value[1]; 
}

char getLeftChild(int index, BinHeap* node){
    char leftChild = node->value[2 * index]; 

    if(2 * index < node->size){
        return leftChild; 
    }
}

char getRightChild(int index, BinHeap* node){
    char leftChild = node->value[(2 * index) + 1]; 

    if((2 * index) + 1 < node->size){
        return leftChild; 
    }
}



int main(){
    BinHeap* buh = createNode(6); 

    


}