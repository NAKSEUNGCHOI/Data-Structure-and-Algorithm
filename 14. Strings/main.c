#include <stdio.h>
#include <stdlib.h>
/**
 *  @brief
 *  A - 65, B - 66, C - 67 ..... Z - 90
 *  a - 97, b - 98, c - 99 ..... z - 122
 */

void *ChargingCase(char *result){
    int i = 0;
    while(result[i] != '\0'){
        if(result[i] >= 65 && result[i] <=90){
            result[i] = result[i] + 32;
        }else if(result[i] >= 'a' && result[i] <= 122){
            result[i] = result[i] - 32;
        }
        i++;
    }
    printf("%s\n", result);
}

void CountingVowels(char *result){
    int i = 0, vowel, consonent;
    while(result[i] != '\0'){
        if(result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u' ||
           result[i] == 'A' || result[i] == 'E' || result[i] == 'I' ||result[i] == 'O' ||result[i] == 'U'){
            vowel++;
        }else if( (result[i] >= 65 && result[i] <= 90) || (result[i] >= 97 && result[i] <= 122) ){
            consonent++;
        }
        i++;
    }
    printf("N. of Vowels is %d.\n", vowel);
    printf("N. of Consonents is %d\n", consonent);
}
int CountWords(char *result){
    int i = 0, count;
    if(result[0] == ' ') count = 0;
    else{
        count = 1;
    }
    while(result[i] != '\0'){
        if(result[i] == ' ' && result[i-1] != ' ' && i != strlen(result)-1){
            count++;
        }
        i++;
    }
    return count;
}
int ValidateWords(char *name){
    int i = 0;
    while(name[i] != '\0'){
        if( !((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122) || (name[i] >= 48 && name[i] <= 57)) ){
            return 0;
        }
        i++;
    }
    return 1;
}

void ReverseString(char *A, int leng){
    char tempo;
    for(int i = 0, j = leng; i < j; i++, j--){
        tempo = A[i];
        A[i] = A[j];
        A[j] = tempo;
    }
    printf("%s\n", A);
}

int Palindrome(char *A){
    char *tempo = A;
    int len = strlen(A)-1;
    char temp;
    for(int i = 0, j = len; i < j; i++, j--){
        if(tempo[i] != A[j]){
            return 0;
        }
    }
    return 1;

}

int FindingDuplicate(char *A){
    int *temp = (int*)calloc(26, sizeof(int));
    int len = strlen(A);
    int i;
    for(i = 0; i < len; i++){
        if(islower(A[i])){
            temp[A[i]-97]++;
        }
    }
    for(int i = 0; i < 26; i++){
        if(temp[i] % 2 == 0 && temp[i] != 0){
            free(temp);
            return 1;
        }
    }
    free(temp);
    return 0;
}



int main(void)
{
    char temp[] = "CrzzzZzzzzzy";
    ChargingCase(&temp);
    char temp1[] = " How are  you ";
    CountingVowels(&temp1);
    int result = CountWords(&temp1);
    printf("The number of words is %d\n", result);
    char temp2[] = "acbdedf?1234";
    int result1 = ValidateWords(&temp2);
    printf("%s\n", result1 ? "true" : "false");
    char A[] = "Python";
    int leng = strlen(A)-1; //
    ReverseString(&A, leng);
    char palin[] = "ACCA";
    int result2 = Palindrome(&palin);
    printf("%s\n", result2 ? "true" : "false");
    char Finding[] = "findcage";
    int result3 = FindingDuplicate(&Finding);
    printf("Duplicate? %s\n", result3 ? "true" : "false");
}
