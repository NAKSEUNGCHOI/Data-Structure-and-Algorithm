#include <stdio.h>
#include <stdlib.h>


int factorial(int x){
    if(x == 0 || x == 1) return 1;
    else return factorial(x-1)*x;
}

int main(){
    int x = 5;
    int r = factorial(x);
    printf("%d", r);
    return 0;
}
