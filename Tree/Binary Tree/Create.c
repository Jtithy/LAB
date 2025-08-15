/* 1. Binary Tree Creation & Traversals
Write a program to:

Create a binary tree using user input.

Perform inorder, preorder, and postorder traversals.

Print the result of each traversal. */


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build the tree recursively
struct Node* buildTree() {
    int value;
    printf("Enter node value (-1 for no node): ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        exit(1);
    }

    if (value == -1) return NULL;

    struct Node* newNode = createNode(value);
    printf("Enter left child of %d:\n", value);
    newNode->left = buildTree();
    printf("Enter right child of %d:\n", value);
    newNode->right = buildTree();

    return newNode;
}

// Traversals
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Free memory
void freeTree(struct Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    printf("=== Binary Tree Creation ===\n");
    struct Node* root = buildTree();

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);

    freeTree(root);
    printf("\n\nTree memory freed.\n");
    return 0;
}
