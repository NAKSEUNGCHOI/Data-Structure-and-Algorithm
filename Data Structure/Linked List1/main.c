/**
 * @file main.c
 * @author Nakseung Choi
 * @date 06-16-2022
 * @brief Linked List Practice1: Inserting a node at the beginning.
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

struct Node* head; // global variable, can be accessed anywhere
/**
 * main()
 * @brief main
 * @param head initialize it to NULL
 * @param Insert(x) call Insert function. It inserts a node at the beginning.
 * @param Print() prints out the result each time.
 */
int main(){
    head = NULL; // empty list;
    printf("How many numbers? \n");
    int n,x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the number: \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
    return 0;
}
/**
 * Insert(int x)
 * @brief Initialize struct.
 * @param temp allocates memory with the size of struct Node to temp.
 * @param temp->data store x in (*temp).data
 * @param temp_next makes it equal to the head
 * @param head head = temp such that the new one comes the head.
 */
void Insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x; // same as (*temp).data = x; dereferencing
    temp->next = head; // same as (*temp).next = NULL;
    head = temp; // link head to the first element
}
/**
 * Print()
 * @brief Print out the results
 * @param temp create a struct pointer to iterate through the nodes and print them out.
 */
void Print(){
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
