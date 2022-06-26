/**
 * main.c
 * @brief Queue ADT (FIFO)
 * Queue is a list or collection with the restriction that insertion can be performed at one end and deletion
 * can be performed at the other end.
 * Queue is used in situations where there is a shared source that is supposed to serve some request.
 * However, the resource can handle only one request at a time.
 * In such a scenario, it makes sense to queue up the requests. The request that comes first, serves first.
 * Printer, process scheduling, and simulating wait are a good example for queue.
 * We can implement queue using arrays and linked lists.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

int Queue[MAX_SIZE];
int front = -1; // initialize front and rear as empty
int rear = -1;

void enqueue(){
    int item;
    if(rear == MAX_SIZE - 1) printf("Overflow \n");
    else{
        if(front == -1)

        front = 0;
        printf("Enter the element to insert in Queue: \n");
        scanf("%d", &item);
        rear = rear + 1;
        Queue[rear] = item;
    }
}
void dequeue(){
    if(front == -1 || front > rear){
        printf("Underflow\n");
        return;
    }else{
        printf("Enter the element to delete from Queue: %d\n", Queue[front]);
        front = front + 1;
    }
}
void show(){
    if(front == -1) printf("Queue is empty\n");
    else{
        printf("\n");
        printf("Queue: \n");
        for(int i = front; i <= rear; i++){
            printf("%d ", Queue[i]);
        }
        printf("\n");
        printf("\n");
        printf("\n");
    }
}



int main(){
    int num;
    while(1){
        printf("1. Enqueue Operation\n");
        printf("2. Dequeue Operation\n");
        printf("3. Display the Queue\n");
        printf("4. Exit\n");
        printf("What would you like to run? ");
        scanf("%d", &num);
        switch(num){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
            default:
                printf("Incorrect choice \n");
        }
    }
}
