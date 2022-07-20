#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

int Missing(struct Array *arr){
    int sum = 0;
    for(int i = 0; i < arr->length; i++){
        sum = sum + arr->A[i];
    }
    int total = (arr->A[arr->length-1]*(arr->A[arr->length-1]+1))/2;
    return total-sum;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12}, 11, 11};
    int result = Missing(&arr);
    printf("The missing number is: %d\n", result);

}
