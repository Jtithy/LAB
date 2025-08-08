/* Create a Doubly linked list which can take character as input, after 
creation write a code which can delete the first element form that linked list. 
Finally print all elements. To create the Linked list, using a loop is mandatory. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

void createList(struct Node** head_ref, int n) {
    if (n <= 0) return;
    char data_char;
    struct Node* current;

    for (int i = 0; i < n; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        if (new_node == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter character for node %d: ", i + 1);
        scanf(" %c", &data_char);
        new_node->data = data_char;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (*head_ref == NULL) {
            *head_ref = new_node;
            current = *head_ref;
        } else {
            current->next = new_node;
            new_node->prev = current;
            current = new_node;
        }
    }
}

void deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    if (*head_ref != NULL) {
        (*head_ref)->prev = NULL;
    }
    free(temp);
}

void printList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter the number of elements to create: ");
    scanf("%d", &n);

    createList(&head, n);

    printf("\nOriginal Doubly Linked List: ");
    printList(head);

    deleteFirst(&head);

    printf("Doubly Linked List after deleting the first element: ");
    printList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}