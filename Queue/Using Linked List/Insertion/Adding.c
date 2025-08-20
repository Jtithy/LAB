#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    char name[50];
    int age;
    char problem[100];
    struct Patient* next;
};

void addPatient(struct Patient** head, char* name, int age, char* problem) {
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    if (newPatient == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->problem, problem);
    newPatient->next = NULL;

    if (*head == NULL) {
        *head = newPatient;
    } else {
        struct Patient* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }
}

void displayPatients(struct Patient* head) {
    if (head == NULL) {
        printf("No patients in the queue.\n");
        return;
    }
    struct Patient* temp = head;
    printf("\n--- Patient Queue ---\n");
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Problem: %s\n", temp->name, temp->age, temp->problem);
        temp = temp->next;
    }
}

int main() {
    struct Patient* patient_queue = NULL;
    char name[50];
    int age;
    char problem[100];
    char choice;

    printf("--- Hospital Patient Queue System ---\n");
    
    while (1) {
        printf("\nDo you want to add a new patient? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'y' || choice == 'Y') {
            printf("Enter patient name: ");
            scanf(" %[^\n]", name);
            
            printf("Enter patient age: ");
            scanf("%d", &age);
            
            printf("Enter patient problem: ");
            scanf(" %[^\n]", problem);
            
            addPatient(&patient_queue, name, age, problem);
            printf("Patient added successfully!\n");
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            printf("Invalid choice. Please enter 'y' or 'n'.\n");
        }
    }
    
    displayPatients(patient_queue);

    // Freeing the allocated memory to prevent memory leaks
    struct Patient* current = patient_queue;
    struct Patient* temp_next;
    while (current != NULL) {
        temp_next = current->next;
        free(current);
        current = temp_next;
    }

    return 0;
}