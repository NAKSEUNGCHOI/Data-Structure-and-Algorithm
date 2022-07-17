#include <stdio.h>
#include <stdlib.h>

/**
 *  main.c
 *  @brief Nested Recursion Example
 */

int fun(int n){
    if( n > 100 ) return n-10;
    return fun( fun(n+11) );

}



int main()
{
    int r;
    r = fun(100);
    printf("%d", r);
    return 0;
}
