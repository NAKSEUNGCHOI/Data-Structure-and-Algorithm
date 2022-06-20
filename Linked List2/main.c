/**
 * @file main.c
 * @author Nakseung Choi
 * @date 06-16-2022
 * @brief Linked List Practice2: Inserting a node at the end.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

int main()
{
    head = NULL;
    printf("How many numbers? \n");
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the number: \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
    return 0;
}

void Insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(head == NULL) head = temp;
    else{
        struct Node* lastNode = head;
        while(lastNode->next != NULL) lastNode = lastNode->next;
        lastNode->next = temp;
    }
}

void Print(){
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
