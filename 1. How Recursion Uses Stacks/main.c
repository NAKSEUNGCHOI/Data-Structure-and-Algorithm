#include <stdio.h>
#include <stdlib.h>

/**
 *  main.c
 *  @brief How Recursion Uses Stack.
 *  Time Complexity: O(n) The time taken is equal to the number of x.
 *  Space Complexity: O(n) n is created in stack section of the memory n number of times.
 *  Space Complexity of iterative way: O(1) n is called once.
 */

/**
 *  void fun1(int x)
 *  @brief Tail recursion.
 */
void fun1(int x){                   // T(n)
    if(x > 0){                      // 1
        printf("%d ", x);           // 1
        fun1(x-1);                  // T(n-1)
    }
}
/**
 *  void iterate(int x)
 *  @brief iterative way corresponding to tail recursion above.
 */
void iterative1(int x){
    while(x > 0){
        printf("%d ", x);
        x--;
    }
}
void iterative2(int x){
    int i = 1;
    while(i <= n){
        printf("%d ", i);
        i++;

    }
}
/**
 *  void fun2(int x)
 *  @brief Head recursion.
 */                                 // T(n) = T(n-1) + 1      when n > 0 ---------------- 1
void fun2(int x){                   // T(n) = 1               when n = 0
    if(x > 0){                      // if T(n) = T(n-1) + 1
        fun2(x-1);                  // T(n-1) = T(n-2) + 1               ---------------- 2
        printf("%d ", x);           // Replacing 2 into 1, T(n) = T(n-2) + 2
    }                               // T(n-2) = T(n-3) + 1
}                                   // Similarly, T(n) = T(n-3) + 3
                                    // Thus, T(n) = T(n-k) + k
int main(){                         // Assuming that n-k = 0, n = k
    int x = 3;                      // T(n) = T(n-n) + n
    fun1(x);                        // T(n) = T(0) + n
    printf("\n");                   // T(n) = 1 + n = O(n)
    iterative1(x);
    printf("\n");

    fun2(x);
    printf("\n");
    iterative2(x);
}
