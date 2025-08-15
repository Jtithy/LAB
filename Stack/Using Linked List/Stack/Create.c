/* 4. Stack using Linked List (Palindrome Check)
Write a program to:

Implement stack using linked list.

Push characters of a string onto the stack.

Pop to reverse the string.

Check if the original string is a palindrome.5. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (!top) return '\0';
    struct Node* temp = top;
    char c = temp->data;
    top = top->next;
    free(temp);
    return c;
}

int main() {
    char str[100], rev[100];
    printf("Enter string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) push(str[i]);
    for (int i = 0; i < strlen(str); i++) rev[i] = pop();
    rev[strlen(str)] = '\0';
    printf("Reversed: %s\n", rev);
    if (strcmp(str, rev) == 0) printf("Palindrome\n");
    else printf("Not Palindrome\n");

    while (top) pop();
    return 0;
}
