#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h>
#include <stdexcept>
#include <iostream> 
#include <vector>


#define DEFAULT_CAPACITY 7

struct Node {
    char data;   
    int freq;    
    Node* left;
    Node* right;  

    
    Node(char d, int f){
        data = d; 
        freq = f; 
        left = nullptr; 
        right = nullptr; 
    }
}; 


struct MinHeap{
    Node** value; 
    int size; 
    int capacity;

    void resize(int new_capacity){
        if(new_capacity <= 0){
            throw std::invalid_argument("New capacity must be greater than 0.");
        }
        Node** temp = new Node*[new_capacity];
        for(int i = 0; i < size; i++){
            temp[i] = value[i]; 
        }
        delete[] value; 
        value = temp;
        capacity = new_capacity; 
    }

    void swap(Node*& a, Node*& b){
        Node* temp = a;
        a = b;
        b = temp;
    }

    void shiftUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2; 
            if(value[index]->freq < value[parent]->freq){
                swap((value[index]), (value[parent]));
                index = parent;
            }else{
                break; 
            }
        }
    }

void sink(int index){
    while(true){
        int leftChild = 2 * index + 1; 
        int rightChild = 2 * index + 2;
        int smallest = index; 

        if(leftChild < size && value[leftChild]->freq < value[smallest]->freq){
            smallest = leftChild;
        }

        if(rightChild < size && value[rightChild]->freq < value[smallest]->freq){
            smallest = rightChild;
        }

        if(smallest != index){
            swap(value[index], value[smallest]); 
            index = smallest; 
        }
        else{
            break; 
        }
    }
}

    MinHeap(){
        value = new Node*[DEFAULT_CAPACITY]; 
        capacity = DEFAULT_CAPACITY; 
        size = 0;
    }

    MinHeap(int cap){
        if (cap < DEFAULT_CAPACITY) {
            cap = DEFAULT_CAPACITY;
        }
        value = new Node*[cap]; 
        capacity = cap; 
        size = 0;
    }

    ~MinHeap() {
        delete[] value;
    }

    void insert(Node* val){
        if(size >= capacity){
            resize((2 * capacity));
        }

        value[size] = val; 
        size = size + 1; 
        shiftUp(size - 1); 
    }

    Node* extractMin(){
        if(size == 0){
            throw std::out_of_range("Error: Heap is empty! Cannot extract minimum.");
        }

        Node* minNode = value[0]; 
        value[0] = value[size - 1];
        size--;
        sink(0);
        return minNode;
    }

    void clear() {
        delete[] value;
        capacity = DEFAULT_CAPACITY;
        size = 0;
        value = new Node*[capacity];
    }

};

void printArr(int arr[], int n){ 
    int i; 
    for (i = 0; i < n; ++i) 
        std::cout << arr[i]; 
  
    std::cout << "\n"; 
} 

int isLeaf(Node* root){ 
    return !(root->left) && !(root->right); 
} 

Node* buildHuffManTree(Node** array, int size){
    Node *left, *right, *top; 

    MinHeap min(size); 
    for(int i = 0; i < size; i++){
        min.insert(array[i]);
    }

    while(min.size > 1){

        left = min.extractMin(); 
        right = min.extractMin(); 

        top = new Node('$', left->freq + right->freq); 
  
        top->left = left; 
        top->right = right; 
  
        min.insert(top); 

    }

    return min.extractMin();

}

void printCodes(Node* root, int arr[], int top, int size, std::vector<std::string> codes){
    if (root->left) { 
        arr[top] = 0; 
        printCodes(root->left, arr, top + 1, size, codes); 
    } 

    if (root->right) { 
        arr[top] = 1;  
        printCodes(root->right, arr, top + 1, size, codes); 
    } 

    if (isLeaf(root)) { 
        int index = static_cast<int>(root->data);
        if (index >= 0 && index < size) { 
            std::string code = "";
            for (int i = 0; i < top; ++i) {
                code += std::to_string(arr[i]);
            }
            codes[index] = code;
        }
    } 

    if (top == 0) {
        for (int i = 0; i < size; i++) {
            if (!codes[i].empty()) { 
                std::cout << static_cast<char>(i) << ":" << codes[i] << "\n";
            }
        }
    }
}

void HuffManCode(Node** array, int size){
    Node* root = buildHuffManTree(array, size); 

    int arr[size] , top = 0; 
    
    std::vector<std::string> codes(size);

    printCodes(root, arr, top, size, codes); 
}



int main(){
    static int size = 128;
    MinHeap minHeap(size);  
    Node* array[size]; 
    for(int i = 0; i < size; i++){
        int input = 0; 
        std::cin >> input; 
        if (input > 0) { // Skips Case where there's zero frequencies
            array[i] = new Node(static_cast<char>(i), input);
        } else {
            array[i] = nullptr;  
        }
    }

   HuffManCode(array, size); 
    for(int i = 0; i < size; i++){
        delete array[i];
    }
}




