/* Create a Doubly linked list which can take character as input, after creation 
write a code which can delete the second element form that linked list. 
Finally print all elements. To create the Linked list, using a loop is mandatory. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

void append(struct Node** head_ref, char new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void deleteSecond(struct Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        return;
    }
    struct Node* second = (*head_ref)->next;
    struct Node* third = second->next;

    (*head_ref)->next = third;
    if (third != NULL) {
        third->prev = *head_ref;
    }
    free(second);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n;
    char data_char;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf(" %c", &data_char);
        append(&head, data_char);
    }

    printf("Original Doubly Linked List: ");
    printList(head);

    deleteSecond(&head);

    printf("Doubly Linked List after deleting the second element: ");
    printList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}