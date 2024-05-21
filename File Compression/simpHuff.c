#include <stdio.h> 
#include <stdlib.h> 

    void checkFrequency(char c[]){

        

    }


int main(){
    int input; 
    int x; 
    char c; 
    printf("How many numbers do you want to input?: "); 

    scanf("%d", &input); 
    getchar(); 
    // Debugging input 
    printf("The numbers of inputs is: %d", input); 

    char character[input]; 


    for(int i = 0; i < input; i++){
        printf("Give me a character: "); 
        scanf("%c", &c); 
        character[i] = c; 
    }

    checkFrequency(&character); 

    return 0; 

}