#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[15];
    int size;
    int length;
};

int BinarySearch(struct Array *arr, int x){
    int left = 0, right = arr->length-1;
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr->A[mid] == x) return mid;

        if(arr->A[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int RBinarySearch(struct Array *arr, int l, int r, int x){
    if(l <= r){
        int m = l + (r - l) / 2;
        if(arr->A[m] == x) return m;
        if(arr->A[m] < x) return RBinarySearch(arr, m+1, r, x);
        else return RBinarySearch(arr, l, m-1, x);
    }
    return -1;
}

int main()
{
    struct Array arr = {{4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43}, 15, 15};
    int result = BinarySearch(&arr, 27);
    printf("%d\n", result);
    result = RBinarySearch(&arr, 0, arr.length-1, 28);
    printf("%d\n", result);
}
