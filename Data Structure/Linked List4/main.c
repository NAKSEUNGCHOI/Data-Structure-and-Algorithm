/**
 * @file main.c
 * @author Nakseung Choi
 * @date 06-16-2022
 * @brief Linked List Practice4: Deleting a node at n-th position.
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * struct Node
 * @brief struct Node
 * @param data data
 * @param next It stores the address of the next data to link them.
 */
struct Node{
    int data;
    struct Node* next;
};

struct Node* head;
/**
 * Insert(int data, int n)
 * @brief Insert function.
 * @param data data
 * @param n n-th position to insert data
 * @param temp1 memory allocation with a size of struct Node* to store the address of the next data.
 * @param temp2 We need this to store new data temporary and points to the next address of the data
 */
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
void Delete(int n){
    struct Node* prev = head;
    if(n == 1){
        head = prev->next; // head now points to second node.
        free(prev);
        return;
    }
    for(int i = 0; i < n-2; i++) prev = prev->next; // prev iterates through and points to (n-1)th Node.
    struct Node* current = prev->next; // pointing to the n-th Node.
    prev->next = current->next; // (n+1)th Node
    free(current); // delete current
}
void Print(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    head = NULL; // empty list
    printf("How many numbers? \n");
    int n,x,m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        printf("Enter the number: \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
    Print();
    printf("Enter the position: \n");
    scanf("%d", &n);
    Delete(n);
    Print();
}
