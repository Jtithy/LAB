#include <stdio.h>
#include <stdlib.h>

struct Node {
    int rollNumber;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int rollNumber) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNumber = rollNumber;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int rollNumber) {
    if (root == NULL) {
        return createNode(rollNumber);
    }
    if (rollNumber < root->rollNumber) {
        root->left = insert(root->left, rollNumber);
    } else if (rollNumber > root->rollNumber) {
        root->right = insert(root->right, rollNumber);
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

struct Node* deleteNode(struct Node* root, int rollNumber) {
    if (root == NULL) {
        return root;
    }

    if (rollNumber < root->rollNumber) {
        root->left = deleteNode(root->left, rollNumber);
    } else if (rollNumber > root->rollNumber) {
        root->right = deleteNode(root->right, rollNumber);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->rollNumber = temp->rollNumber;
        root->right = deleteNode(root->right, temp->rollNumber);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->rollNumber);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int roll, numNodes, i, rollToDelete;

    printf("Enter the number of student roll numbers to insert: ");
    scanf("%d", &numNodes);

    printf("Enter %d roll numbers:\n", numNodes);
    for (i = 0; i < numNodes; i++) {
        scanf("%d", &roll);
        root = insert(root, roll);
    }

    printf("\nInorder traversal of the BST (before deletion): ");
    inorderTraversal(root);
    printf("\n");

    printf("Enter the roll number to delete: ");
    scanf("%d", &rollToDelete);

    root = deleteNode(root, rollToDelete);

    printf("\nInorder traversal of the BST (after deletion): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
