#include <stdio.h>
#include <stdlib.h>
/**
 *  int fibo(int n)
 *  @brief fibonacci numbers with iterative method
 */
int fibo(int n){
    int s, t0 = 0, t1 = 1;
    for(int i = 2; i <= n; i++){
        s = t0+t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
int rfib(int n){
    if(n <= 1) return n;
    return rfib(n-2) + rfib(n-1);
}
int main()
{
    int n;
    while(1){
        printf("Enter a number: \n");
        scanf("%d", &n);
        int result = fibo(n);
        printf("%d\n", result);
    }
    return 0;
}
