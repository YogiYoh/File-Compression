#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h>


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
    int rightChild = node->value[(2 * index) + 1]; 

    if((2 * index) + 1 < node->size){
        return rightChild; 
    }

    return -1; 
}


void shiftUp(BinHeap* node, int index){
    while(index > 0){
        int parent = (index - 1) / 2; 
        if(node->value[index] > node->value[parent]){
            swap(&(node->value[index]), &(node->value[parent]));
            index = parent;
        }else{
            break; 
        }
    }
}


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
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

void sink(int index, BinHeap* node){
        int leftChild = (2 * index) + 1; 
        int rightChild = (2 * index) + 2;
        int large = index; 

        if (leftChild < node->size && node->value[leftChild] > node->value[large]) {
           large = leftChild;
        }

        if (rightChild < node->size && node->value[rightChild] > node->value[large]) {
           large = rightChild;
        }
        
        if(large == index){
            return; 
        }

        swap(&(node->value[index]), &(node->value[large])); 
        index = large; 
        sink(index, node);  

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

BinHeap* delete(BinHeap* node, int index){
    if(node->size > node->capacity){
        fprintf(stderr, "Error: Heap Size is greater than Heap Capacity!\n");
        return node; 
    }else if(node->size <= index || index < 0){
        fprintf(stderr, "Error: Index is out of bounds!\n");
        return node; 
    }else if(node->size < node->capacity / 2){
        resize(node, (node->capacity / 2));
    }

    swap(&node->value[index], &node->value[node->size - 1]);
    node->size--;
    if (index < node->size) {
        shiftUp(node, index);
        sink(index, node);
    }
}


void deleteHeap(BinHeap* node){
    if(node == NULL){
        return; 
    }

    if(node->value != NULL){
        free(node->value); 
    }
    free(node); 

}

void printBin(BinHeap* node){
    for(int i = 0; i < node->size; i++){
        printf("The Value of Bin[%d] is: %d \n", i, node->value[i]);
    }
}



int main(){

    int ARRAY []= {2, 7, 26, 25, 19, 17, 1, 90, 3, 36}; 
    BinHeap* buh = createNode(10); 


    for(int i = 0; i < 10; i++){
        insert(buh, ARRAY[i]); 
    }


    printBin(buh); 


    deleteHeap(buh); 


}