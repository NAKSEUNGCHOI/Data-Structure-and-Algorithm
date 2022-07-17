#include <stdio.h>
#include <stdlib.h>

/**
 *  main.c
 *  @brief the static variable is created in code section of the memory.
 *  This variable gets created once, so it is same as creating it as a global variable.
 *  This is more beneficial b/c all of the functions can share it.
 */

int fun(int n){
    static int x = 0;
    if(n > 0){
        x++;
        return fun(n-1) + x;
    }
    return 0;
}


int main()
{
    int r, x = 5;
    r = fun(x);
    printf("%d ", r);
}
