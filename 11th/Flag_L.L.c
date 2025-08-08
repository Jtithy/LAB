/* Create a circular linked list with Flag, 
Delete first element from this linked list and print all elements. 
To create and print the Linked list, using a loop is mandatory. */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteFirst(Node** head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    *head = (*head)->next;
    last->next = *head;
    free(temp);
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    int flag = 1;
    do {
        printf("%d -> ", current->data);
        current = current->next;
        if (current == head && flag == 1) {
            flag = 0;
        }
    } while (current != head || flag);
    printf("Head\n");
}

int main() {
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    printf("Original circular linked list:\n");
    printList(head);

    deleteFirst(&head);

    printf("\nCircular linked list after deleting the first element:\n");
    printList(head);

    return 0;
}