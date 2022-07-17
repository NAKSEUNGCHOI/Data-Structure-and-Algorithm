#include <stdio.h>
#include <stdlib.h>

/**
 *  main.c
 *  @brief Indirect Recursion Example.
 */
void fun2(int x);

void fun1(int x){
    if(x > 0){
        printf("%d ", x);
        fun2(x-1);
    }
}
void fun2(int x){
    if(x > 1){
        printf("%d ", x);
        fun1(x/2);
    }

}
int main(){
    int x = 20;
    fun1(x);
}
