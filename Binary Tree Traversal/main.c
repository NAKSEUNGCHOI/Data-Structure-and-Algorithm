/**
 * @brief Binary Tree Traversal
 * Process of visiting each node in the tree exactly once in some order.
 * 1. Breadth-first Traversal
 *    Level-order
 * 2. Depth-first Travesal
 *  <root><left><right> -Preorder
 *  <left><root><right> -Inorder
 *  <left><right><root> -postorder
 *
 *                       F              -> L-0
 *                    /     \
 *                   D       J          -> L-1
 *                  / \     / \
 *                 B   E   G   K        -> L-2
 *                / \ / \ / \ / \
 *               A   C       I          -> L-3
 *                          /
 *                         H            -> L-4
 *
 * Preorder(DLR) visit(data) left right If forgot, watch "mycodeschool"
 * Inorder (LDR) left visit(data) right
 * Postorder(LRD) left right data
 *
 *
 * This is an implementation for level-order traversal(Breath-first Traversal)
 * Queue(FIFO)
 *
 * LevelOrder using queue.
 * The code is from geeksforgeeks.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct node{
    char data;
    struct node* left;
    struct node* right;
};

struct node** createQueue(char*, char*);
void enQueue(struct node**, char*, struct node*);
struct node* deQueue(struct node**, char*);

void printLevelOrder(struct node* root){
    char front, rear;
    struct node** queue = createQueue(&front, &rear);
    struct node* temp_node = root;

    while (temp_node){
        printf("%c ", temp_node->data);

        /*Enqueue left child */
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        /*Enqueue right child */
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
}

/*UTILITY FUNCTIONS*/
struct node** createQueue(char* front, char* rear){
    struct node** queue = (struct node**)malloc(
        sizeof(struct node*) * MAX_Q_SIZE);

    *front = *rear = 0;
    return queue;
}

void enQueue(struct node** queue, char* rear, struct node* new_node){
    queue[*rear] = new_node;
    (*rear)++;
}

struct node* deQueue(struct node** queue, char* front){
    (*front)++;
    return queue[*front - 1];
}
struct node* newNode(char data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main(){
    struct node* root = newNode('M');
    root->left = newNode('B');
    root->right = newNode('Q');
    root->left->left = newNode('A');
    root->left->right = newNode('C');

    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    getchar();
    return 0;
}
