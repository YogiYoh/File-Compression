#include <stdlib.h> 
#include <stdio.h> 


#define DEFAULT_CAPACITY 7


typedef struct Node{
    char* value; 
    int size; 
    int capacity;

}BinHeap;

BinHeap* createNode(){
    BinHeap* node = (BinHeap*)(malloc)(sizeof(BinHeap)); 
    node->value = (char*)(malloc)(DEFAULT_CAPACITY * sizeof(char)); 

    node->capacity = DEFAULT_CAPACITY; 
    node->size = 0;

    return node; 
}

