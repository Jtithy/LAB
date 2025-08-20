#include <stdio.h>
#include <stdlib.h>

struct Node {
    int productId;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->productId = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int id) {
    if (root == NULL) {
        return createNode(id);
    }
    if (id < root->productId) {
        root->left = insert(root->left, id);
    } else if (id > root->productId) {
        root->right = insert(root->right, id);
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int id) {
    if (root == NULL) {
        printf("Product ID not found.\n");
        return root;
    }
    if (id < root->productId) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->productId) {
        root->right = deleteNode(root->right, id);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            printf("Product ID deleted successfully.\n");
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            printf("Product ID deleted successfully.\n");
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->productId = temp->productId;
        root->right = deleteNode(root->right, temp->productId);
    }
    return root;
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->productId);
}

void freeBST(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    int choice, id;
    do {
        printf("\n--- Product ID BST Manager ---\n");
        printf("1. Insert Product ID\n");
        printf("2. Delete Product ID\n");
        printf("3. Display Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Product ID to insert: ");
                scanf("%d", &id);
                root = insert(root, id);
                break;
            case 2:
                printf("Enter Product ID to delete: ");
                scanf("%d", &id);
                root = deleteNode(root, id);
                break;
            case 3:
                printf("Postorder Traversal: ");
                if (root == NULL) {
                    printf("BST is empty.\n");
                } else {
                    postorderTraversal(root);
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    freeBST(root);
    return 0;
}