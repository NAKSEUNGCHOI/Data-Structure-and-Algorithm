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

/**
 * @brief H is created as an integer which is 4 bytes, 32 bits.
 * the number of alphabet is 25 from 0. For example, the first letter is f and f is 102 in ASCii chart.
 * Then, A[i]-97 = f - 97 = 102 - 97 = 5. Thus, push 1 to the 5th bit field of x.
 * Using bit masking (&), check whether x & H is greater than 0 or not.
 * If it is, that means we have a duplicate, if not, update it to H like H = x | H;
 */
void FindingDuplicateUsingBitwiseOperator(char *A){
    int H = 0, x, count = 0;
    for(int i = 0; A[i] != '\0'; i++){
        x = 1;
        x = x << (A[i]-97);
        if((x & H) > 0){
            printf("%c is duplicate\n", A[i]);
            count++;
        }else{
            H = x | H;
        }
    }
    if(count == 0){
        printf("No duplicate!\n");
    }
}

void Anagram(char *A, char *B){
    int H = 0, x, count = 0;
    int len1 = strlen(A), len2 = strlen(B);
    if(len1 != len2) exit(0);
    for(int i = 0; A[i] != '\0'; i++){
        x = 1;
        H |= x << (A[i]-97);
    }
    for(int i = 0; B[i] != '\0'; i++){
        x = 1;
        x = x << (B[i]-97);
        if((H & x) == 0){
            printf("%c, They are not Anagram!\n", B[i]);
            count++;
        }
    }
    if(count == 0){
        printf("They are Anagram!\n");
    }

}
void Anagram2(char *A, char *B){
    int *temp = (int *)calloc(52, sizeof(int));
    int count = 0;
    for(int i = 0; A[i] != '\0'; i++){
        if(A[i] >= 65 && A[i] <= 90){
            temp[A[i]-65]++;
        }else if(A[i] >= 97 && A[i] <= 122){
            temp[A[i]-71]++;
        }
    }
    for(int i = 0; B[i] != '\0'; i++){
        if(B[i] >= 65 && B[i] <= 90){
            temp[B[i]-65]--;
            if(temp[B[i]-65] < 0){
                printf("They are not anagram!\n");
                count++;
            }
        }else if(B[i] >= 97 && B[i] <= 122){
            temp[B[i]-71]--;
            if(temp[B[i]-71] < 0){
                printf("They are not anagram!\n");
                count++;
            }
        }
    }
    if(count == 0){
        printf("They are anagram!\n");
    }
}

/**
 * @brief permutation
 *
 *             State Space Tree
 *
 *                    O
 *           /        |        \
 *          A         B         C
 *         / \       / \       / \
 *        B   C     A   C     A   B
 *       /     \   /     \   /     \
 *      C       B C       A B       A
 *      |       | |       | |       |
 *     ABC    ACB BAC   BCA CAB    CBA
 *
 *          1. Back Tracking
 *          2. brute Force
 *          3. Recursion
 *
 *          n! numbers possible. ABCD = 4 letters = 4! = 4*3*2*1 = 24 possible words.
 *
 *
 */
 void permutation(char *s, int k){
    static int A[10] = {0}, count = 0;
    static char result[10];
    int i;
    if(s[k] == '\0'){
        result[k] = '\0';
        count++;
        printf("%d. %s\n", count, result);
    }else{
        for(int i = 0; s[i] != '\0'; i++){
            if(A[i] == 0){
                result[k] = s[i];
                A[i] = 1;
                permutation(s, k+1);
                A[i] = 0;
            }
        }
    }
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
    FindingDuplicateUsingBitwiseOperator(&Finding);
    char A1[] = "medical";
    char B1[] = "decimal";
    char A2[] = "MeDiCAl";
    char B2[] = "DeCiMAL";
    Anagram(&A1, &B1);
    Anagram2(&A2, &B2);
    char permu[] = "ABCD";
    permutation(&permu, 0);
}
