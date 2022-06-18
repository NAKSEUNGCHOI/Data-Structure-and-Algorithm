/**
 * @file main.c
 * @author Nakseung Choi
 * @copyright https://www.techiedelight.com/reverse-linked-list-part-2-recursive-solution/
 * @brief reverse linked list using recursion. A new node is inserted at the beginning of the linked list.
 */

#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};

// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

// Recursive function to reverse a linked list. It reverses the given
// linked list by fixing the head pointer and then `.next` pointers
// of every node in reverse order.
void reverse(struct Node** head)
{
    struct Node* first;
    struct Node* rest;

    // empty list base case
    if (*head == NULL) {
        return;
    }

    first = *head;                  // suppose first = {1, 2, 3}
    rest = first->next;             // rest = {2, 3}

    // empty rest base case
    if (rest == NULL) {
        return;
    }

    reverse(&rest);                 // recursively reverse the smaller {2, 3} case
                                    // after: rest = {3, 2}

    first->next->next = first;      // put the first item at the end of the list
    first->next = NULL;             // (tricky step — make a drawing)
    *head = rest;                   // fix the head pointer
}

int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(keys)/sizeof(keys[0]);

    struct Node* head = NULL;
    for (int i = n - 1; i >=0; i--) {
        push(&head, keys[i]);
    }

    printList(head);
    reverse(&head);
    printList(head);

    return 0;
}
