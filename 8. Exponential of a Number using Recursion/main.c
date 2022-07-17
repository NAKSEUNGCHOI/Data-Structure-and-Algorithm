#include <stdio.h>
#include <stdlib.h>

int power(int m, int n){
    if( n == 0 ) return 1;
    else return pow(m,n-1)*m;
}
int power1(int m, int n){
    if( n == 0 ) return 1;
    if( (n % 2) == 0) return pow(m*m, n/2);
    return m * pow(m*m, (n-1)/2);
}

int main()
{
    int r = power(3,4);
    printf("1. %d\n", r);

    r = power1(9, 3);
    printf("2. %d\n", r);


    return 0;
}
