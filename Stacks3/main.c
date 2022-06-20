/**
 *  @file   main.c
 *  @author Nakseung Choi University of Washington ECE
 *  @date   06-20-2022
 *  @brief  reverse string using stack.
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    char str[100], temp;
    int i;
    int j = 0;
    printf("Enter the string: \n");
    gets(str);

    i = 0;
    j = strlen(str) - 1;
    printf("%d", j);

    while(i < j){
        temp = str[i]; // store str[0]
        str[i] = str[j]; // swap str[0] and str[laststring]
        str[j] = temp; // store the first(temp) into str[laststring]
        i++; // increment by one
        j--; // decrement by one.
    }

    printf("Reversed string is %s\n", str);
}
