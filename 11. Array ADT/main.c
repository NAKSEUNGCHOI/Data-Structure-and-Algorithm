#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void Append(struct Array *arr, int x){
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x){
    if(index >= 0 && index <= arr->length){
        for(int i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;

    }
}

int Delete(struct Array *arr, int index){
    int x;
    if(index >= 0 && index < arr->length){
        x = arr->A[index];
        for(int i = index; i < arr->length; i++){
            arr->A[i] = arr->A[i+1];
            arr->length--;
            return x;
        }
    }
}

void Display(struct Array arr){
    printf("The elements are: \n");
    for(int i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int main(){
    struct Array arr = {{2,3,4,5,6}, 10, 5};
    Insert(&arr, 5, 10);
    Display(arr);
    printf("%d", Delete(&arr, 5));
    Display(arr);
    return 0;
}
