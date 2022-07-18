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

int Get(struct Array *arr, int index){
    if(index >= 0 && index < arr->length){
        return arr->A[index-1];
    }
}
void Set(struct Array *arr, int index, int x){
    if(index >= 0 && index < arr->length){
        arr->A[index-1] = x;
    }
}
void Min(struct Array *arr){
    printf("%d\n", arr->A[0]);
}
void Max(struct Array *arr){
    printf("%d\n", arr->A[arr->length-1]);
}
void Avg(struct Array *arr){
    int average;
    for(int i = 0; i < arr->length; i++){
        average = average + arr->A[i];
    }
    printf("%lf\n", (double)average/(arr->length));
}

void Reverse(struct Array *arr){
    struct Array *temp = (struct Array*)malloc(sizeof(struct Array));
    for(int i = arr->length-1, k = 0; i >=0; i--, k++){
        temp->A[k] = arr->A[i];
        printf("%d ", temp->A[k]);
    }
}

void Display(struct Array *arr){
    for(int i = 0; i < arr->length; i++){
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}


int main()
{
    struct Array arr = {{4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43}, 15, 15};
    int result = BinarySearch(&arr, 27);
    printf("%d\n", result);
    result = RBinarySearch(&arr, 0, arr.length-1, 27);
    printf("%d\n", result);
    printf("%d\n", Get(&arr, 2));
    //Set(&arr, 2, 6);
    Display(&arr);
    Max(&arr);
    Min(&arr);
    Avg(&arr);
    Reverse(&arr);
}
