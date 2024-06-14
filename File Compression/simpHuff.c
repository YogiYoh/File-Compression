#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h> 
#include "MinHeap.c"

typedef struct Node{
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


    void checkFrequency(char c[], int input, HuffMan* node)
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
        printf("\n");
        x++; 
    }

    HuffMan* node = createHuff(input); 
    

    checkFrequency(character, input, node); 

    frequencyMsg(node); 

    return 0; 

}

// int main(){

//     int ARRAY []= {2, 7, 26, 25, 19, 17, 1, 90, 3, 36}; 
//     MinHeap* buh = createNode(10); 


//     for(int i = 0; i < 10; i++){
//         insert(buh, ARRAY[i]); 
//     }


//     printBin(buh); 


//     deleteHeap(buh); 


// }