#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int size;
    int top;
    char *S;
};
void create(struct Stack *st, int x){
    st->size = x;
    st->top = -1;
    st->S = (char*)malloc(st->size);
}
void push(struct Stack *st, char *temp){
    if(st->top == st->size-1) printf("Stack Overflow\n");
    else{
        st->top++;
        st->S[st->top] = temp;
    }
}
void pop(struct Stack *st, char *temp){
    if(st->top == -1) printf("Stack Underflow\n");
    else{
        if(temp == '}' && st->S[st->top] == '{')
            st->S[st->top--];
        else if(temp == ')' && st->S[st->top] == '(')
            st->S[st->top--];
        else if(temp == ']' && st->S[st->top] == '[')
            st->S[st->top--];
        else{
            printf("Syntax Error\n");
            return;
        }

    }
}
int isEmpty(struct Stack *st){
    if(st->top == -1) return 1;
    else return 0;
}

void isMatching(struct Stack *st, char *temp, int x){
    for(int i = 0; temp[i] != '\0'; i++){
        if(temp[i] == '(' || temp[i] == '{' || temp[i] == '[')
            push(st, temp[i]);
        else if(temp[i] == ')' || temp[i] == '}' || temp[i] == '['){
            pop(st, temp[i]);
        }
    }
    if(isEmpty(st) == 1)
        printf("Matching!\n");
    else
        printf("Not matching!\n");
}

int main(){
    struct Stack st;
    char temp[] = "({(a+b)}*(c-d))";
    int x = strlen(temp);
    create(&st, x);
    isMatching(&st, &temp, x);

}
