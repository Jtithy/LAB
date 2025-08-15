/* 2. Height & Node Count in Binary Tree
Write a program that:

Takes a binary tree from Problem 1.

Calculates and displays:

Height of the tree.

Total number of nodes.

Number of leaf nodes. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode() {
    int value;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &value);
    if (value == -1) return NULL;
    struct Node* newNode = createNode(value);
    printf("Enter left child of %d\n", value);
    newNode->left = insertNode();
    printf("Enter right child of %d\n", value);
    newNode->right = insertNode();
    return newNode;
}

int height(struct Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaf(struct Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int main() {
    struct Node* root = insertNode();
    printf("Height: %d\n", height(root));
    printf("Total Nodes: %d\n", countNodes(root));
    printf("Leaf Nodes: %d\n", countLeaf(root));

    return 0;
}
