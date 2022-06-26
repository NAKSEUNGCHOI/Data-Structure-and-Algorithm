/**
 * main.c
 * @brief binary tree: each node can have only two children at most.
 * strict/proper binary tree: each node can have either 2 or 0 children.
 * complete binary tree: all levels except possibly the last are completely filled and all nodes
 * are as left as possible
 * perfect binary tree: maximum No. of nodes in a binary tree with height, "h"
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
 *
 *                  O                           O                        O
 *                /   \                       /   \                   /     \
 *               O     O                     O     O                 O       O
 *              / \   / \                   / \   / \               / \     / \
 *             O   O O   O                 O   O O   O             O   O   O   O
 *                / \                     / \                     / \ / \ / \ / \
 *               O   O                   O   O                   O  O O O O O O  O
 *          Strict Binary Tree         Complete Binary Tree     Perfect Binary Tree
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
