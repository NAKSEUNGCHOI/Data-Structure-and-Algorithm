#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    if(temp == NULL) printf("Stack Overflow\n");
    else{
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}
int pop(){
    struct Node *temp;
    int x = -1;
    if(top == NULL) printf("Stack is empty\n");
    else{
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}
void Display(){
    struct Node *p;
    p = top;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int peek(int position){
    struct Node *temp = top;
    int i;
    for(i = 0, temp != NULL; i < position-1; i++){
        temp = temp->next;
    }
    if(temp != NULL){
        return temp->data;
    }else{
        return -1;
    }
}
int stackTop(){
    if(top != NULL){
        return top->data;
    }
    return -1;
}
int isEmpty(){
    return top ? 0 : 1;
}
int isFull(){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    int r = temp?1:0;
    free(temp);
    return r;
}

int main()
{
    push(10);
    push(20);
    push(30);
    Display();
    printf("Popped: %d\n", pop());
    Display();
}
