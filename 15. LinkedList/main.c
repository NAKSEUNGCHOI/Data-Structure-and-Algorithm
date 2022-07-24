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

void create(int *A, int n){
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
}
int count(struct Node *p){
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
}
int count_recursive(struct Node *p){
    if(p != NULL) return count_recursive(p->next)+1;
    else{
        return 0;
    }
}
int sum(struct Node *p){
    int sum;
    while(p != NULL){
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}
int maximum(struct Node *p){
    int maximum = INT_MIN;
    while(p != NULL){
        if(p->data > maximum){
            maximum = p->data;
        }
        p = p->next;
    }
    return maximum;
}
struct Node* search(struct Node *p, int key){
    while(p != NULL){
        if(key == p->data){
            return p;
        }
        p = p->next;
    }
    return p;
}
struct Node* Improved_search(struct Node *p, int key){
    /*Move to head method*/
    /*Moving a number that has been found to the first */
    struct Node *q = NULL;
    while(p != NULL){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return p;
}
void InsertAtTheBeginning(struct Node *p, int x){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = first;
    first = temp;
}
void Insert_NthPosition(struct Node *p, int x, int index){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    p = first;
    if(p == NULL) return 0;
    for(int i = 0; i < index-1; i++){
        p = p->next;
        if(p == NULL){
            printf("Overflow: %d\n", index);
            break;
        }
    }
    temp->next = p->next;
    p->next = temp;
}
void InsertatLast(struct Node *p, int x){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(first == NULL) first = temp;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = temp;
}
void InsertSorted(struct Node *p, int x){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *q = NULL;
    temp->data = x;
    temp->next = NULL;
    if(first == NULL) first = temp;
    else{
        while(p && p->data < x){
            q = p;
            p = p->next;
        }
        if(p == first){
            temp->next = first;
            first = temp;
        }else{
            temp->next = p;
            q->next = temp;
        }
    }

}
void Delete_Nth(int index){
    struct Node *p, *q;
    if(index == 1){
        p = first;
        first = first->next;
        free(p);
    }else{
        p = first;
        q = NULL;
        for(int i = 0; i < index-1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
    }
}
int sorted(struct Node *p){
    int x = INT_MIN;
    if(p->next == NULL) return 1;
    else{
        while(p != NULL){
            if(x > p->data) return 0;
            else{
                x = p->data;
                p = p->next;
            }
        }
    }
    return 1;
}
void DeleteDuplicate(struct Node *p){         //                            p     q
    struct Node *q = p->next;                 //          MM    MM    MM    MM    MM
    while(q != NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }else{
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

int main(){
    int A[] = {3, 5, 7, 10, 15, 25, 8, 32, 2};
    /*1. Create LinkedList*/
    create(&A, 9);

    /*2. Display: One with while, the other with recursion. */
    Display(first);
    Display_Recursive(first);
    printf("\n");

    /*3. Count the number of traversal taken place*/
    int a = count(first);
    printf("1. The number of traversal: %d\n", a);
    a = count_recursive(first);
    printf("2. The number of traversal: %d\n", a);

    /*4. Sum of data*/
    a = sum(first);
    printf("The sum of data: %d\n", a);

    /*5. Maximum value */
    a = maximum(first);
    printf("The maximum number: %d\n", a);


    /*6. search a number*/
    struct Node *temp = search(first, 10);
    printf("1. The value found: %d\n", temp->data);
    struct Node *temp1 = Improved_search(first, 15);
    printf("2. The value found: %d\n", temp1->data);

    /*7. Insert a node*/
    int index = 10;
    printf("\n");
    printf("Before Inserting:\n");
    Display(first);
    InsertAtTheBeginning(first, 6);
    printf("After Inserting at the beginning:\n");
    Display(first);
    printf("Before Inserting:\n");
    Display(first);
    Insert_NthPosition(first, 6, index);
    printf("After Inserting %d after %dth node:\n", 6, index);
    Display(first);
    InsertatLast(first, 23);
    Display(first);
    int B[] = {10, 20, 30, 40, 50};
    create(&B, 5);
    InsertSorted(first, 20);

    /*8. Delete a n-th node */
    Display(first);
    Delete_Nth(6);
    Display(first);

    /*9. Check if a linked list is sorted*/
    printf("Sorted? %s\n", sorted(first) ? "true" : "false");

    /*10. Delete a duplicate */
    DeleteDuplicate(first);
    Display(first);

    return 0;

}
