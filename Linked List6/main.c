/**
 * @file main.c
 * @author Nakseung Choi
 * @date 06-16-2022
 * @brief Linked List Practice6: Reversing nodes using PrintRecursion.
 * Iterative approach to reversing nodes would be better and efficient.
 * This is because Iterative approach only uses one temp variable,
 * whereas recursive approaches uses implicit memory space of stack section
 * for a number of function calls.
 */
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void Insert(struct Node** head, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
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
void PrintRecursion(struct Node* p){
    if(p == NULL){
        printf("\n");
        return;
    }
    PrintRecursion(p->next);
    printf("%d ", p->data);
}

int main(){
    struct Node* head = NULL;
    Insert(&head, 15);
    Insert(&head, 3);
    Insert(&head, 23);
    Insert(&head, 38);
    Print(head);

    PrintRecursion(head);
}
