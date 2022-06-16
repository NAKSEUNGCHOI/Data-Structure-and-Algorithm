/**
 * @file main.h
 * @author Nakseung Choi
 * @date 06-16-2022
 * @brief header file for main.c.
 * Insertion a node at beginning.
 */

/**
 * struct Node
 * @brief Initialize struct.
 * @param data int data.
 * @param Node* a struct pointer pointing to the address of the next variable to link them together.
 */
struct Node{
    int data;
    struct Node* next; // points to the address of the next index
};

/**
 * Function prototype
 * The detailed descriptions are written in main.c.
 */
void Insert(int x);
void Print();
