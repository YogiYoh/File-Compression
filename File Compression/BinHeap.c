#include <stdlib.h> 
#include <stdio.h> 


#define DEFAULT_CAPACITY 7


typedef struct Node{
    int* value; 
    int size; 
    int capacity;

}BinHeap;

BinHeap* defaultNode(){
    BinHeap* node = (BinHeap*)(malloc)(sizeof(BinHeap)); 
    node->value = (int*)(malloc)(DEFAULT_CAPACITY * sizeof(int)); 

    node->capacity = DEFAULT_CAPACITY; 
    node->size = 0;

    return node; 
}

BinHeap* createNode(int capacity){
    BinHeap* node = (BinHeap*)(malloc)(sizeof(BinHeap)); 
    node->value = (int*)(malloc)(capacity * sizeof(int)); 

    node->capacity = capacity; 
    node->size = 0;

    return node; 
}

void resize(BinHeap* node, int new_capacity){
    if(node->capacity < new_capacity){
        int* temp = (int*)(malloc)(new_capacity * sizeof(int)); 
        for(int i = 0; i < node->capacity; i++){
            temp[i] = node->value[i]; 
        }

        int* old = node->value; 
        node->value = temp;
        node->capacity = new_capacity; 
        free(old);
    }
}

int findMax(int* value){
    return value[1]; 
}

int getLeftChild(int index, BinHeap* node){
    int leftChild = node->value[2 * index]; 

    if(2 * index < node->size){
        return leftChild; 
    }

    return -1; 
}

int getParentNode(int index, int* value){
    int parent = index / 2; 
    if(parent != 0){
        return value[parent]; 
    }else{
        return findMax(value); 
    }

    return -1; 
}



int getRightChild(int index, BinHeap* node){
    int leftChild = node->value[(2 * index) + 1]; 

    if((2 * index) + 1 < node->size){
        return leftChild; 
    }

    return -1; 
}

void swim(int size, BinHeap* node){

    if(size <= 0){
        return; 
    }

    int parentNode = (size - 1) / 2; 

    if(node->value[size] <= node->value[parentNode]){
        return; 
    }

    int value = node->value[parentNode]; 

    node->value[parentNode] = node->value[size]; 

    node->value[size] = value; 
    swim(parentNode, node); 
}


BinHeap* insert(BinHeap* node, int value){
    
    if(node->size > node->capacity){
        fprintf(stderr, "Error: Heap Size is greater than Heap Capacity!\n");
        return node; 
    }else if(node->size == node->capacity){
        resize(node, (2 * node->capacity));
    }

        
    node->value[node->size] = value; 
    node->size = node->size + 1; 
    swim(node->size - 1, node); 
    return node; 
}


BinHeap* deleteHeap(BinHeap* node){
    if(node == NULL){
        return; 
    }

    if(node->value != NULL){
        free(node->value); 
    }
    free(node); 

}

void printBin(BinHeap* node){
    for(int i = 0; i < node->capacity; i++){
        printf("The Value of Bin[%d] is: %d \n", i, node->value[i]);
    }
}



int main(){
    BinHeap* buh = createNode(6); 

    insert(buh, 10); 
    printf("Size: %d\n", buh->size); 
    printBin(buh);
    insert(buh, 9);
    printf("Size: %d\n", buh->size); 
    printBin(buh);
    insert(buh, 30);
    printf("Size: %d\n", buh->size); 
    printBin(buh); 


    deleteHeap(buh); 


}