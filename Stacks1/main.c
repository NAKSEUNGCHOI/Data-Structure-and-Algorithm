/**
 *  @file   main.c
 *  @author Nakseung Choi University of Washington ECE
 *  @date   06-19-2022
 *  @brief  Simple implementation of Stacks using an array.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1; // empty stack if -1.

void Push(int x){
    if(top == MAX_SIZE -1){
        printf("Erorr: stack overflow\n");
        return;
    }
    A[++top] = x; // This is equal to top++; and A[top] = x;

}
void Pop(){
    if(top == -1){
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}
int Top(){
    return A[top];
}
void Print(){
    int i;
    printf("Stack: ");
    for(int i = 0; i <= top; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main(){
    Push(2); Print();
    printf("Top is %d.\n", Top());
    Push(5); Print();
    printf("Top is %d.\n", Top());
    Push(10); Print();
    Pop();   Print();
    Push(12); Print();
    printf("Top is %d.\n", Top());
}
