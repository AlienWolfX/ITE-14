#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    char type[10];
    struct Node* next;
} Node;

Node* createNode(char name[], char type[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->type, type);
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, char name[], char type[]) {
    Node* newNode = createNode(name, type);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Name: %s Type: %s\n", current->name, current->type);
        current = current->next;
    }
}

void freeList(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    FILE* file;
    char name[100];
    char type[10];
    Node* regularList = NULL;
    Node* vipList = NULL;

    file = fopen("../input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, " %[^,], %[^\n]", name, type) == 2) {
        if (strcmp(type, "regular") == 0) {
            insertNode(&regularList, name, type);
        } else if (strcmp(type, "VIP") == 0) {
            insertNode(&vipList, name, type);
        } else {
            printf("Invalid client type: %s\n", type);
        }
    }

    fclose(file);

    printf("Regular Clients:\n");
    displayList(regularList);
    printf("\n");
    printf("VIP Clients:\n");
    displayList(vipList);

    freeList(regularList);
    freeList(vipList);

    return 0;
}
