#include <stdio.h>
#include <stdlib.h> // Required for malloc

// Define the structure for a BST node
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

// Function to create a new BST node
struct Node* createNode(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->key = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new key into the BST
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return createNode(key);
    }

    // Otherwise, recur down the tree
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    // If the key is already present, do nothing (assuming unique keys or
    // handling duplicates as per requirement, here we ignore duplicates)
    return node;
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key) {
        return root;
    }

    // Key is greater than root's key
    if (root->key < key) {
        return search(root->right, key);
    }

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to perform inorder traversal of the BST (to show sorted order)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    int prices[] = {35, 21, 78, 12, 30, 18, 55, 100, 10, 60};
    int n = sizeof(prices) / sizeof(prices[0]);
    struct Node* root = NULL; // Initialize the root of the BST
    int i, searchKey;

    // Insert all prices into the BST
    for (i = 0; i < n; i++) {
        root = insert(root, prices[i]);
    }

    printf("Prices inserted into the Binary Search Tree. (Inorder Traversal for sorted view):\n");
    inorderTraversal(root);
    printf("\n");

    printf("Enter a price to search for: ");
    scanf("%d", &searchKey);

    struct Node* resultNode = search(root, searchKey);

    if (resultNode != NULL) {
        printf("Price %d found in the Binary Search Tree.\n", searchKey);
    } else {
        printf("Price %d not found in the Binary Search Tree.\n", searchKey);
    }

    // Note: For a complete program, you might want to add a function to free the allocated memory
    // for the BST nodes to prevent memory leaks, especially in larger applications.

    return 0;
}
