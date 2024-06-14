#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h> 
#include "MinHeap.c"

typedef struct Huffman{
    int* frequency; 
    char* characters;
    int uniqueChars; 
}HuffMan;


HuffMan* createHuff(int capacity){
    HuffMan* node = (HuffMan*)(malloc)(sizeof(HuffMan)); 
        
    node->frequency = (int*)(malloc)(sizeof(int) * capacity); 

    node->characters = (char*)(malloc)(sizeof(char) * capacity); 
    node->uniqueChars = 0; 
    return node; 
}


void frequency(char c[], int input, HuffMan* node)
    {
        for(int i = 0; i < input; i++){
            bool found = false; 
            char currentChar = c[i]; 
            if(c[i] >= 'A' && c[i] <= 'Z'){
                for(int j = 0; j < node->uniqueChars; j++){
                    if(node->characters[j] == currentChar){
                        node->frequency[j]++; 
                        found = true;
                        break;  
                    }

                }
            }
            if(!found){
                node->characters[node->uniqueChars] = currentChar;
                node->frequency[node->uniqueChars] = 1;
                node->uniqueChars++;
            }
        }
    }


    void frequencyMsg(HuffMan* node){
        for(int i = 0; i < node->uniqueChars; i++){
            printf("The character %c has the frequency of %d\n", node->characters[i], node->frequency[i]); 
        }
    }

void deleteHuff(HuffMan* node){
    if(node == NULL){
        return; 
    }

    if(node->frequency != NULL){
        free(node->frequency); 
    }


    if(node->characters != NULL){
        free(node->characters); 
    }
    free(node); 

}



int main(){
    int input; 
    int x = 0; 
    char c; 
    printf("How many numbers do you want to input?: "); 
    scanf("%d", &input); 
    // Debugging input 
    printf("The numbers of inputs is: %d\n", input); 
    
    getchar();
    char character[input]; 
    while(x < input){
        printf("Give me a character: "); 
        scanf(" %c", &character[x]); 
        character[x] = toupper(character[x]); 
        x++; 
    }


    HuffMan* node = createHuff(input); 
    frequency(character, input, node); 

    frequencyMsg(node);

    MinHeap* min = createNode(node->uniqueChars); 

    for(int i = 0; i < node->uniqueChars; i++){
        insert(min, node->frequency[i]); 
    }

    printBin(min); 

    deleteHuff(node); 

    deleteHeap(min); 

    return 0; 

}

