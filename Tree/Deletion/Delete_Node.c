/* 5. Construct the Binary tree by user input given by 
the following graph and delete node three and check the BT 
configuration is intact by checking the inorder traversal. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

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

// Build the tree recursively using user input
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

// Delete a node by value
struct Node* deleteNode(struct Node* root, int value) {
    if (!root) return NULL;
    if (root->data == value) return NULL; // Remove this node entirely
    root->left = deleteNode(root->left, value);
    root->right = deleteNode(root->right, value);
    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
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
    printf("=== Construct Binary Tree ===\n");
    struct Node* root = buildTree();

    printf("\nInorder before deletion: ");
    inorder(root);

    int delVal = 3;
    printf("\nDeleting node %d...\n", delVal);
    root = deleteNode(root, delVal);

    printf("Inorder after deletion: ");
    inorder(root);

    freeTree(root);
    printf("\nTree memory freed.\n");
    return 0;
}
