/* Create a circular linked list with sentinel value by using a loop, 
insert one element at the first position of this linked list and print 
all elements. To create and print the Linked list, using a loop is mandatory. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtBeginning(Node* sentinel, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;

    if (sentinel->next == sentinel) {
        newNode->next = sentinel;
        sentinel->next = newNode;
    } else {
        newNode->next = sentinel->next;
        sentinel->next = newNode;
    }
}

void printList(Node* sentinel) {
    if (sentinel->next == sentinel) {
        printf("The list is empty.\n");
        return;
    }
    Node* current = sentinel->next;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != sentinel);
    printf("SENTINEL\n");
}

int main() {
    Node* sentinel = (Node*)malloc(sizeof(Node));
    if (sentinel == NULL) {
        return 1;
    }
    sentinel->data = -1;
    sentinel->next = sentinel;

    for (int i = 0; i < 5; i++) {
        insertAtBeginning(sentinel, i + 1);
    }

    printf("Circular linked list with sentinel:\n");
    printList(sentinel);

    insertAtBeginning(sentinel, 0);

    printf("\nCircular linked list after inserting '99' at the beginning:\n");
    printList(sentinel);

    return 0;
}