#include <stdio.h>
#include <stdlib.h>

double taylor(int x, int n){
    double s = 1;
    double num = 1;
    double deno = 1;
    for(int i = 1; i <= n; i++){
        num *= x;
        deno *= i;
        s += num/deno;
    }
    return s;
}
double e(int x, int n){
    static double s;
    if( n == 0 ) return s;
    s = 1 + x*s / n;
    return e(x,n-1);
}

int main()
{
    double r = taylor(2, 10);
    printf("%lf\n", r);
    double x = e(2, 10);
    printf("%lf\n", x);
}
