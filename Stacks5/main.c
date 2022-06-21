/**
 *  @file   main.c
 *  @author Nakseung Choi University of Washington ECE
 *  @date   06-20-2022
 *  @brief  Parentheses balance checker using stacks. LIFO.
 *  Stack is a suitable data structure for parentheses balance checker.
 *  As an opening parentheses comes in, it pushes the parentheses into stack. In contrast,
 *  it pops the opening parentheses as the corresponding closing parentheses comes in.
 */

#include <stdio.h>
#include <stdlib.h>
#define bool int

struct Node{
    int data;
    struct Node* next;
};

/**
 * Function prototypes
 */
void Push(struct Node** top_ref, int data);
int Pop(struct Node** top_ref);

bool matchingPair(char character1, char character2){
    if(character1 == '(' && character2 == ')'){
        return 1;
    }else if(character1 == '{' && character2 == '}'){
        return 1;
    }else if(character1 == '[' && character2 == ']'){
        return 1;
    }else{
        return 0;
    }
}
/**
 * bool bracketBalanceChecker(char exp[])
 * @brief if exp[i] is equal to an opening parentheses, it calls Push function.
 * If exp[i] is equal to a closing parentheses, it calls matchingPair function to check if balanced or unbalanced by returning
 * either 1 or 0. 1 if balanced, and 0 if unbalanced.
 *
 */
bool bracketBalanceChecker(char exp[]){
    int i = 0; // counter
    struct Node* stack = NULL;
    while(exp[i]){

        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '['){
            Push(&stack, exp[i]);
        }

        if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']'){
            if (stack == NULL){
                return 0;
            }
            else if(!matchingPair(Pop(&stack), exp[i])){
                return 0;
            }
        }
        i++;
    }

    if (stack == NULL)
        return 1; // balanced
    else
        return 0; // not balanced
}

int main(){
    int i, n;
    char *exp;

    printf("Number of elements to be entered: \n"); // Getting the number of input
    scanf("%d",&n);

    if(n % 2 == 0){
        exp = (char*)calloc(n, sizeof(char*)); // dynamic allocation for char array.

        printf("Enter %d parentheses: \n", n);
        for(i = 0 ; i < n; i++) {
           scanf("%s", &exp[i]);
        }

        if (bracketBalanceChecker(exp)){
            printf("Balanced \n");
        }else{
            printf("Not Balanced \n");
        }
        return 0;

    }else{
        printf("Not Balanced \n"); // if not even, automatically unbalanced return 0
        return 0;
    }
}
void Push(struct Node** top_ref, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    if(temp == NULL) {
        printf("Stack overflow \n");
        exit(0);
    }
    temp->data = data;
    temp->next = (*top_ref);
    (*top_ref) = temp;
}
int Pop(struct Node** top_ref){
    char res;
    struct Node* top;
    if (*top_ref == NULL) {
        printf("Stack overflow n");
        exit(0);
    }else{
        top = (*top_ref);
        res = top->data;
        (*top_ref) = top->next;
        free(top);
        return res;
    }

}
