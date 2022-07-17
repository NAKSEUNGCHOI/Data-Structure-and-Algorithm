#include <stdio.h>
#include <stdlib.h>

int r = 0;

int sum(int x){
    if(x == 0) return 0;
    else return sum(x-1)+x;
}

int main(){
    int x = 10;
    r = sum(x);
    printf("%d", r);
    return 0;
}
