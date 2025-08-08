/* Create a circular linked list with Flag, insert one element at the 
first position of this linked list and print all elements. 
To create and print the Linked list, using a loop is mandatory. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void createCircularList(struct Node** flag, int n) {
    if (n <= 0) return;
    int value;
    struct Node* tail = *flag;
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = *flag;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtFirst(struct Node** flag, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    if ((*flag)->next == *flag) {
        newNode->next = *flag;
        (*flag)->next = newNode;
    } else {
        newNode->next = (*flag)->next;
        (*flag)->next = newNode;
    }
}

void printList(struct Node* flag) {
    if (flag->next == flag) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = flag->next;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != flag);
    printf("Head\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct Node* flag = (struct Node*)malloc(sizeof(struct Node));
    flag->next = flag;

    printf("Enter the elements: ");
    createCircularList(&flag, n);

    printf("\nOriginal circular linked list:\n");
    printList(flag);

    int newValue;
    printf("\nEnter the value to insert at the first position: ");
    scanf("%d", &newValue);
    insertAtFirst(&flag, newValue);

    printf("\nCircular linked list after inserting at the first position:\n");
    printList(flag);

    struct Node* current = flag->next;
    while (current != flag) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(flag);

    return 0;
}