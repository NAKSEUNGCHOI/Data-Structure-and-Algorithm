/**
 * @file main.c
 * @author Nakseung Choi
 * @date 06-16-2022
 * @brief Linked List Practice3: Inserting a node at n-th position.
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
 * main()
 * @brief main function. calls Insert and Print function
 * @param head initializes head to NULL.
 */
int main(){
    head = NULL;
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,4);
    Print();
}
/**
 * Insert(int data, int n)
 * @brief Insert function.
 * @param data data
 * @param n n-th position to insert data
 * @param temp1 memory allocation with a size of struct Node* to store the address of the next data.
 * @param temp2 We need this to store new data temporary and points to the next address of the data
 */
void Insert(int data, int n){
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    temp1->data = data;
    temp1->next = NULL;
    if(n == 1){
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node* temp2 = head;
    for(int i = 0; i < n-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;

}
/**
 * Print()
 * @brief Print function to output the results.
 * @param temp creates a Node pointer to store head.
 * @param while iterate through the links to print out.
 */
void Print(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
