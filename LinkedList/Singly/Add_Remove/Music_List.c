#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    int duration;
    struct Song* next;
};

struct Song* createSong(const char* title, const char* artist, int duration) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    if (newSong == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strncpy(newSong->title, title, sizeof(newSong->title) - 1);
    newSong->title[sizeof(newSong->title) - 1] = '\0';
    strncpy(newSong->artist, artist, sizeof(newSong->artist) - 1);
    newSong->artist[sizeof(newSong->artist) - 1] = '\0';
    newSong->duration = duration;
    newSong->next = NULL;
    return newSong;
}

void addSong(struct Song** head, const char* title, const char* artist, int duration) {
    struct Song* newSong = createSong(title, artist, duration);
    if (newSong == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = newSong;
    } else {
        struct Song* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSong;
    }
    printf("Song added successfully.\n");
}

void removeSong(struct Song** head, const char* title) {
    if (*head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Song* current = *head;
    struct Song* prev = NULL;
    if (strcmp(current->title, title) == 0) {
        *head = current->next;
        free(current);
        printf("Song removed successfully.\n");
        return;
    }
    while (current != NULL && strcmp(current->title, title) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Song not found.\n");
        return;
    }
    prev->next = current->next;
    free(current);
    printf("Song removed successfully.\n");
}

void printPlaylist(struct Song* head) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    printf("--- Current Playlist ---\n");
    struct Song* current = head;
    while (current != NULL) {
        printf("Title: %s, Artist: %s, Duration: %d seconds\n", current->title, current->artist, current->duration);
        current = current->next;
    }
    printf("------------------------\n");
}

void freePlaylist(struct Song** head) {
    struct Song* current = *head;
    struct Song* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Song* playlist = NULL;
    int choice;
    char title[100];
    char artist[100];
    int duration;
    do {
        printf("\n--- Music Playlist Manager ---\n");
        printf("1. Add a new song\n");
        printf("2. Remove a song by title\n");
        printf("3. View playlist\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                printf("Enter artist name: ");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = '\0';
                printf("Enter duration (in seconds): ");
                scanf("%d", &duration);
                while (getchar() != '\n');
                addSong(&playlist, title, artist, duration);
                break;
            case 2:
                printf("Enter title of the song to remove: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                removeSong(&playlist, title);
                break;
            case 3:
                printPlaylist(playlist);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    freePlaylist(&playlist);
    return 0;
}