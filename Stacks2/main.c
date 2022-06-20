/**
 *  @file   main.c
 *  @author Nakseung Choi University of Washington ECE
 *  @date   06-19-2022
 *  @brief  Simple implementation of Stacks using Linked List.
 *  The time complexity of stack is Big O(1).
 *  The Linked list that inserts a list at the end of the list has a time complexity of Big O(n)
 *  This is because it has to iterate through the list until the end to add one.
 *  However, the linked list that inserts a list at the beginning of the list does not go through
 *  this iteration. Thus, the time complexity is Big O(1), same as the time complexity of stack.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->link = top;
    top = temp;
}
void Pop(){
    struct Node* temp;
    if(top == NULL) return;
    temp = top;
    top = temp->link;
    free(temp);
}
void Top(){
    if(top != NULL){
        printf("Element on top is %d.\n", top->data);
    }else{
        printf("The stack is empty. Nothing to print out.\n");
    }
}
void Print(){
    struct Node* temp = top;
    printf("The stack is ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
void isEmpty(){
    return top == NULL;
}

int main(){
    Push(10); Top(); Print();
    Push(34); Top(); Print();
    Push(12); Top(); Print();
    Push(21); Top(); Print();
    Push(5);  Top(); Print();
    Pop();    Top(); Print();
    Push(10); Top(); Print();

}
