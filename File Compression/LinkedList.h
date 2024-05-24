#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <ostream>
#include <stdexcept>


struct Node{
    char data;
    Node* next;

    Node(char value){
        data = value;
        next = nullptr;
    }

    bool operator==(const Node& other){
        return data == other.data;
    }

};

struct LinkedList{
    Node* head; 

    LinkedList(){
        head = NULL; 
    }

    void prepend(char value){
        if(head == NULL){
            head = (struct Node*)malloc(sizeof(struct Node)); 
            head->data = value; 
        }else{
            Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
            temp->data = value; 
            temp->next = head; 
            head = temp; 
        }
    }


    void append(char value){
        if(head == NULL){
            head = (struct Node*)malloc(sizeof(struct Node)); 
            head->data = value; 
        }else{
            Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
            temp->data = value; 
            Node* last = head; 
            while(last->next != NULL){
                last = last->next;
            }
        }
    }

}; 


#endif