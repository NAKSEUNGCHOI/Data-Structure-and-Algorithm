#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *last, *temp;
    first = (struct Node*)malloc(sizeof(struct Node*));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for(int i = 1; i < n; i++){
        temp = (struct Node*)malloc(sizeof(struct Node*));
        temp->data = A[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}
int Length(struct Node *p){
    int len = 0;
    while( p != NULL){
        len++;
        p = p->next;
    }
    return len;
}
void Display(struct Node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void Insert(int x){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->prev = NULL;
    temp->next = first;
    first->prev = temp;
    first = temp;
}
void Insert2(struct Node *p, int x, int index){
    struct Node *temp;
    if(index < 0 || index > Length(p)) return;
    if(index == 0){
        temp = (struct Node*)malloc(sizeof(struct Node*));
        temp->data = x;
        temp->prev = NULL;
        temp->next = first;
        first->prev = temp;
        first = temp;
    }else{
        for(int i = 0; i < index-1; i++){
            p = p->next;
        }
        temp = (struct Node*)malloc(sizeof(struct Node*));
        temp->data = x;
        temp->next = p->next;
        temp->prev = p;
        if( p->next != NULL ) p->next->prev = temp;
        p->next = temp;
    }
}
int Delete(struct Node *p){
    int x;
    p = first;
    first = first->next;
    x = p->data;
    free(p);
    if(first != NULL) first->prev = NULL;
    return x;
}
int Delete2(struct Node *p, int index){
    struct Node *q;
    int x = -1;
    if( index < 1 || index > Length(p)) return -1;
    if(index == 1){
        first = first->next;
        if(first != NULL) first->prev = NULL;

        x = p->data;
        free(p);
    }else{
        for(int i = 0; i < index-1; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next != NULL){
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
    return x;
}
void Reverse(struct Node *p){
    struct Node *temp;

    while(p != NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(  p != NULL && p->next == NULL ) first = p;
    }
}


int main(){
    int A[] = {1, 3, 5, 6, 8};
    create(&A, 5);
    /*1. Create a doubly linked list*/
    printf("1. Doubly linked list created:\n");
    Display(first);

    /*2. insert a node*/
    printf("2. Insert\n");
    Insert(10);
    Display(first);

    /*3. Insert a node after n-th*/
    printf("3. Insert a node after %d\n", 0);
    Insert2(first, 15, 0);
    Display(first);

    /*4. Delete a node*/
    printf("4. Delete a node at the beginning\n");
    int x = Delete(first);
    printf("Deleted: %d\n", x);
    Display(first);

    /*5. Delete a node at a given index*/
    printf("5. Delete a node at a given index\n");
    int y = Delete2(first, 1);
    printf("Delete: %d\n", y);
    Display(first);

    /*6. Reverse a doubly linked list*/
    printf("6. Reverse a doubly linked list\n");
    Reverse(first);
    Display(first);

}
