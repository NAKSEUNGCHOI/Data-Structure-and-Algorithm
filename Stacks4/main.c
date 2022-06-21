/**
 *  @file   main.c
 *  @author Nakseung Choi University of Washington ECE
 *  @date   06-20-2022
 *  @brief  Reversing a linked list using stacks. LIFO.
 *  The time complexity of stack is Big O(1).
 *  The Linked list that inserts a list at the end of the list has a time complexity of Big O(n)
 *  This is because it has to iterate through the list until the end to add one.
 *  However, the linked list that inserts a list at the beginning of the list does not go through
 *  this iteration. Thus, the time complexity is Big O(1), same as the time complexity of stack.
 */
#include <stdio.h>
#include <stdlib.h>
struct linked_list{
    int data;
    struct linked_list* next;
};

int stack[30], top = -1;

/**
 * Insert(struct linked_list** head, int x)
 * @brief Inserting data at the beginning
 */
int Insert(struct linked_list** head, int x){
    struct linked_list* temp = (struct linked_list*)malloc(sizeof(struct linked_list*));
    temp->data = x;
    temp->next = (*head);
    (*head) = temp;
}
/**
 * Push(struct linked_list* head)
 * @brief Pushing data in stack
 */
int Push(struct linked_list* head){
    printf("Linked list: \n");
    while(head != NULL){
        printf("%d ", head->data);
        stack[++top] = head->data;
        head = head->next;
    }
}

/**
 * Push(struct linked_list* head)
 * @brief print from stack. It is LIFO
 */
void printfromstack(){
    printf("\nStack:\n");
    while(top>=0) printf("%d ", stack[top--]);
}


int main(){
    struct linked_list* head = NULL;
    Insert(&head, 5);
    Insert(&head, 8);
    Insert(&head, 13);
    Insert(&head, 19);
    Push(head);
    printfromstack();
}
