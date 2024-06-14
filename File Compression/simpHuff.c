#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
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




    void checkFrequency(char c[], int input)
    {
        int frequency[26] = {0}; // 26 is the amount of char in alphabet 

        for(int i = 0; i < input; i++){
            if(c[i] >= 'A' && c[i] <= 'Z'){
                frequency[c[i] - 'A']++; 
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
    

    checkFrequency(character, input); 

    return 0; 

}