/**
 *  main.c
 *  @date July-05-2022
 *  @brief This is an example of Bubble sort.
 *  BubbleSort function is called in the main function. This functions takes three arguments: int array, int size,
 *  and int function pointer. Two for loops were employed to sort the order. Therefore, the time complexity is BigO(n^2)
 *  The space complexity is BigO(n). The function pointer points to the function with two parameters: A[k] and A[k+1].
 *  These parameters go into the compare function and return 1 if A[k] > A[k+1]. Otherwise, return -1;
 *  Back at the line where if statement is in the BubbleSort function, if the return value was 1, then it changes the positions.
 */

#include <stdio.h>
#include <stdlib.h>

int compare(int x, int y){
    if(x > y) return 1;
    else return -1;
}

void BubbleSort(int *A, int size, int (*compare)(int, int) ){
    int temp;
    for(int i = 0; i < size; i++){
        for(int k = 0; k < size-1; k++){
            if(compare(A[k], A[k+1]) > 0){
                temp = A[k];
                A[k] = A[k+1];
                A[k+1] = temp;
            }
        }
    }
}


int main(){
    int A[] = {5, 4, 6, 3, 7, 2, 1, 8};
    int size = sizeof(A)/sizeof(int);
    BubbleSort(&A, size, compare);

    for(int i = 0; i < size; i++) printf("%d ", A[i]);
}
