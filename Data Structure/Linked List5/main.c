/**
 * @file main.c
 * @author Nakseung Choi
 * @date 06-16-2022
 * @brief Linked List Practice4: Deleting a node at n-th position.
 */
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void Insert(struct Node** head, int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;
}
void Print(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
static void Reverse(struct Node** head){
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while(current != NULL){
        next = current->next; // store the next address from current into next
        current->next = prev; // alter the current address to previous address
        prev = current; // set previous to current
        current = next; // set current to next
    }// do steps above until current is not equal to the last one.
    *head = prev; // when current is equal to NULL, set head to prev(the last node.)
}
int main(){
    struct Node* head = NULL;
    Insert(&head, 32);
    Insert(&head, 5);
    Insert(&head, 7);
    Insert(&head, 12);
    printf("Given linked list: \n");
    Print(head);

    Reverse(&head);
    printf("Reversed linked list: \n");
    Print(head);

}
