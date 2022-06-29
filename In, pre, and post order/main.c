/**
 * main.c
 * @brief
 * 1. binary tree: each node can have only two children at most.
 * 2. strict/proper binary tree: each node can have either 2 or 0 children.
 * 3. complete binary tree: all levels except possibly the last are completely filled and all nodes
 * are as left as possible
 * 4. perfect binary tree: maximum No. of nodes in a binary tree with height, "h"
 * = 2^0 + 2^1 + 2^2 + .... + 2^h
 * = 2^(h+1) -1
 * = 2^(No. of levels) - 1
 * height of a binary tree can be found using this equation:
 * n = 2^(h+1) -1
 * n+1 = 2^(h+1)
 * log2(n+1) = h+1
 * log2(n+1) - 1 = h
 * The time complexity for binary tree is O(h) at worst, where h is the height of the binary tree.
 * At best, which is a minimum height, is O(log2(n))
 * The ideal goal is programmers want to keep the binary tree minimum possible, most commonly called "balanced."
 * This is where a new binary comes in play. That is Balanced Binary tree.
 * Balanced Binary Tree: The difference between height of left and right subtree for every node is not more than k(mostly 1)
 * The height of empty tree is -1. Similarly, the height of tree with 1 node is 0.
 * diff = | h_left - h_right |
 * Binary tree can be implemented using these:
 * a) dynamically created nodes.
 * b) arrays
 * In case of using arrays, complete binary tree can be created using arrays.
 * Tracking the indexes can be done using these equations below:
 *
 * for node at index i,
 *
 * 1. left-child-index = 2i+1
 * 2. right-child-index = 2i+2
 *
 * array is also used for heaps.
 *
 * 5. Binary Search Tree: left index is lesser and the right index is greater than the parent node.
 *
 *                  O                        O                        O
 *                /   \                    /   \                   /     \
 *               O     O                  O     O                 O       O
 *              / \   / \                / \   / \               / \     / \
 *             O   O O   O              O   O O   O             O   O   O   O
 *                / \                  / \                     / \ / \ / \ / \
 *               O   O                O   O                   O  O O O O O O  O
 *          Strict Binary Tree      Complete Binary Tree     Perfect Binary Tree
 *
 *                  15
 *                /    \
 *              12      20
 *             /  \    /  \
 *            8   13  17  22
 *          Binary Search Tree
 *
 *          ** Finding the min and max value using a recursive way **
 * Height of tree:
 *
 * Height of tree is number of edges in longest path from root to a leaf node.
 * This means that height of tree is equal to height of root.
 * Height of node is number of edges in longest path from a node to a leaf node.
 *
 * Depth:
 * number of edges in path from root to that node.
 *
 *
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
#include <stdbool.h>
#include <math.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int FindMin(struct Node* root){
    if(root == NULL){
        printf("Error: Tree is empty\n");
        return -1;
    }else if(root->left == NULL){
        return root->data;
    }
    return FindMin(root->left);
}

int FindMax(struct Node* root){
    if(root == NULL){
        printf("Error: Tree is empty\n");
        return -1;
    }else if(root->right == NULL){
        return root->data;
    }
    return FindMin(root->right);
}

int FindHeight(struct Node* root){
    if(root == NULL) return -1;
    int result = fmax(FindHeight(root->left), FindHeight(root->right)) + 1;
    return result;
}

struct Node* minValueNode(struct Node* node){
    struct Node* current = node;
    while( current && current->left != NULL ) current = current->left;
    return current;
};

struct Node* Insert(struct Node* root, int data){
    if(root == NULL){ // empty tree
        root = newNode(data);
        return root;
    }else if(data <= root->data){
        root->left = Insert(root->left, data);
    }else{
        root->right = Insert(root->right, data);
    }
    return root;
}
struct Node* Delete(struct Node* root, int data){
    if(root == NULL) return root; //return if empty
    if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) Delete(root->right, data);
    else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}

void inOrder(struct Node* root){
    if(root != NULL) {
        inOrder(root->left);
        printf("%d \n", root->data);
        inOrder(root->right);
    }
}
void PreOrder(struct Node* root){
    if(root == NULL) return;
    printf("%d", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
void PostOrder(struct Node* root){
    if(root == NULL) return;
    PreOrder(root->left);
    PreOrder(root->right);
    printf("%d", root->data);
}


int main(){
    struct Node* root = NULL;
    root = Insert(root, 25);
    int data, value;
    while(1){
        data = 0;
        printf("1. Insert Operation\n");
        printf("2. Delete Operation\n");
        printf("3. Inorder Operation\n");
        printf("4. Pre-order Operation\n");
        printf("5. Post-order Operation\n");
        printf("6. Search Minimum Value\n");
        printf("7. Search Maximum Value\n");
        printf("8. Search Height of Tree\n");
        printf("9. Exit Operation\n");
        printf("Enter a number: ");
        scanf("%d", &value);
        switch(value){
            case 1:
                printf("Enter the number to be inserted in binary tree: ");
                scanf("%d", &data);
                Insert(root, data);
                break;
            case 2:
                printf("Enter the number to be deleted from binary tree: ");
                scanf("%d", &data);
                Delete(root, data);
                break;
            case 3:
                inOrder(root);
                break;
            case 4:
                inOrder(root);
                break;
            case 5:
                inOrder(root);
                break;
            case 6:
                printf("The minimum value is %d\n.", FindMin(root));
                break;
            case 7:
                printf("The maximum value is %d\n.", FindMax(root));
                break;
            case 8:
                printf("The height of tree is %d\n.", FindHeight(root));
                break;
            case 9:
                exit(0);
            default:
                printf("Incorrect Operation. Try again.");
        }
    }
}
