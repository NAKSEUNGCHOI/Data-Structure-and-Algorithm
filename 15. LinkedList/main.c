#include <stdio.h>
#include <stdlib.h>

/*self-referential structure*/
/**
 *  if(p == NULL)
 *  if(p == 0)
 *  if(!p)
 *  These are all same. False
 * --------------------------
 *  if(p != NULL)
 *  if(p != 0)
 *  if(p)
 *  These are all same. True
 * --------------------------
 *  if(p->next == NULL)
 * --------------------------
 *  if(p->next != NULL)
 *
 */
struct Node{
    int data;
    struct Node *next;
}*first = NULL;

struct Node *head;

void create(int A[], int n){
    int i;
    struct Node *temp, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void Display(struct Node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void Display_Recursive(struct Node *p){
    if(p != NULL){
        printf("%d ", p->data);
        Display_Recursive(p->next);
    }
    printf("\n");
}


int main(){
    int A[] = {3, 5, 7, 10, 15};
    /*1. Create LinkedList*/
    create(&A, 5);
    /*2. Display: One with while, the other with recursion. */
    Display(first);
    Display_Recursive(first);




    return 0;

}
