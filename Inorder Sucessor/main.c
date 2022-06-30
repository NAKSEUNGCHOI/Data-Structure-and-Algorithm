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

struct Node* Insert(struct Node* root, int data){
    if(root == NULL){
        root = newNode(data);
        return root;
    }else if(data <= root->data){
        root->left = Insert(root->left, data);
    }else{
        root->right = Insert(root->right, data);
    }
    return root;
}

struct Node* Inorder(struct Node* root){
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

struct Node* Find(struct Node* root, int data){
    //Traverse to find the same value
    if(root == NULL) return;
    else if(root->data == data) return root;
    else if(root->data < data) Find(root->right, data);
    else Find(root->left, data);
}

struct Node* FindMin(struct Node* root){
    if(root == NULL) return;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct Node* Getsuccessor(struct Node* root, int data){
    // Search the node - O(h)
    // Find the current value
    struct Node* current = Find(root, data);
    if(current == NULL) return NULL;
    // Case 1: Node has a right subtree.
    if(current->right != NULL){
        return FindMin(current->right);
    }else{ // Case 2: No right subtree
        struct Node* successor = NULL;
        struct Node* ancestor = root;
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

int main(){
    /* Code to test the logic creating an example tree
                               20
                             /    \
                            8      22
                           / \
                          4   12
                         /   /  \
                        2   10   14
    */
    int x;
    struct Node* root = NULL;
    root = Insert(root, 20);    root = Insert(root, 8);
    root = Insert(root, 22);    root = Insert(root, 4);
    root = Insert(root, 2);     root = Insert(root, 12);
    root = Insert(root, 10);    root = Insert(root, 14);

    printf("Inonder Traversal: ");
    Inorder(root);
    printf("\n");

    while(1){
        printf("Enter a number to find a successor: \n");
        scanf("%d", &x);
        struct Node* successor = Getsuccessor(root, x);
        if(successor == NULL) printf("No successor Found\n");
        else printf("The successor of %d is: %d\n", x, successor->data);
    }
    return 0;
}
