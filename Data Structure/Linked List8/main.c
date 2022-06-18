/**
 * @file main.c
 * @author Nakseung Choi
 * @date Jun-18-2022
 * @brief Doubly Linked List Implementation. It enables reverse look up.
 * Extra memory usage for pointer to previous node. Singly 8 bytes while double is 12 bytes.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* getNewNode(int x){
    /*
     * If you create struct like
     * struct Node myNode
     * myNode.data = x;
     * myNode.next = NULL;
     * myNode.prev = NULL;
     * this is a local variable and it will be cleared from memory when function call finishes
     * This is because local variables live in "stack section" of memory.
     * That's why we declare as a pointer, which stores it in "heap section."
     * This is why we use malloc function to store it in heap section to use it until you free the memory.
     */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    (*newNode).data = x; // same as newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void InsertAtHead(int x){
    struct Node* newNode = getNewNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void InsertAtTail(int x){
    struct Node* temp = getNewNode(x);
    if(head == NULL){
        head = temp;
    }else{
        struct Node* lastNode = head;
        while(lastNode->next != NULL) lastNode = lastNode->next;
        lastNode->next = temp;
        temp->prev = lastNode;
    }

}
void Print(){
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void ReversePrint(){
    struct Node* temp = head;
    if(temp == NULL) return;
    while(temp->next != NULL){
        temp = temp->next;
    }
    printf("Reverse: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(){
    head = NULL;
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
    InsertAtTail(5); Print(); ReversePrint();
    InsertAtTail(3); Print(); ReversePrint();

}
