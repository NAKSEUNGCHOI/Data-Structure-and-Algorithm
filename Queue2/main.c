#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int Front(){
	if(front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	return front->data;
}
void enqueue(){
    int x;
    printf("Enter a value to insert in the queue: ");
    scanf("%d", &x);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->next = NULL;
    if(rear == NULL && front == NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;

}
void dequeue(){
    struct Node* temp = front;
    if(front == NULL){
        printf("Underflow \n");
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
    }
    free(temp);
}
void show(){
    struct Node* temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int temp;
    while(1){
        printf("1. Enqueue Operation \n");
        printf("2. Dequeue Operation \n");
        printf("3. Display the Queue \n");
        printf("4. Display the front \n");
        printf("5. exit \n");
        printf("Enter Operation: \n");
        scanf("%d", &temp);
        switch(temp){
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
                printf("%d \n",Front());
                break;
            case 5:
                exit(0);
            default:
                printf("Incorrect Input\n");
        }
    }
}
