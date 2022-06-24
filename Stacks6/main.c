/**
 *  main.c
 *  @brief currently the code has an error.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 101

char A[MAX_SIZE];
int top = -1; // empty stack if -1.

void Push(char x){
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
char Top(){
    return A[top];
}


bool isOperator(char x[])
{
    printf("%c\n", x);
    switch(x){
        case '+':
            return true;
        case '-':
            return true;
        case '/':
            return true;
        case '*':
            return true;
    }
    return false;
}

// Convert prefix to Postfix expression
char preToPost(char pre_exp[])
{

    // length of expression
    int length = strlen(pre_exp);
    // reading from right to left
    for(int i = length - 1; i >= 0; i--)
    {
        // check if symbol is operator
        if(isOperator(pre_exp[i]))
        {
            // pop two operands from stack
            char op1 = Top();
            printf("hey: %c\n", op1);
            Pop();
            char op2 = Top();
            //printf("hey: %s", op2);
            Pop();

            // concat the operands and operator
            char temp = op1 + op2 + pre_exp[i];

            // Push string temp back to stack
            Push(temp);
        }

        // if symbol is an operand
        else {

            // push the operand to the stack
            Push(pre_exp[i]);
        }
    }

    // stack contains only the Postfix expression
    return Top();
}

// Driver Code
int main()
{
    char pre_exp[] = "*-A/BC-/AKL";
    printf("Postfix: %s", preToPost(pre_exp));
    return 0;
}
