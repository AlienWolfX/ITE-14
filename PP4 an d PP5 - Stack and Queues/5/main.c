#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define PRINT

typedef struct Node {
    char info[15];
    char name[50];
    char type[20];
    struct Node* next;
} Node;

typedef struct RegularQueue { 
    Node* front;
    Node* rear;
} regularQueue;

typedef struct VIPStack {
    Node* top;
} vipStack;

Node* createNode(char info[], char name[], char type[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->info, info);
    strcpy(newNode->name, name);
    strcpy(newNode->type, type);
    newNode->next = NULL;
    return newNode;
}

void enqueue(regularQueue* queue, char info[], char name[], char type[]) {
    Node* newNode = createNode(info, name, type);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void push(vipStack* stack, char info[], char name[], char type[]) {
    Node* newNode = createNode(info, name, type);
    newNode->next = stack->top;
    stack->top = newNode;
}

void printRegularQueue(regularQueue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        printf("Regular client %s lines up at RegularQueue\n", current->name);
        current = current->next;
    }
}

void printVIPStack(vipStack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        printf("VIP client %s lines up at VIPStack\n", current->name);
        current = current->next;
    }
}

void freeNode(Node* node) {
    if (node != NULL) {
        free(node->next);
        free(node);
    }
}

int main() {
    FILE* fp;
    char name[50];
    char type[20];
    char info[15];
    char line[100];
    regularQueue RegularQueue = {NULL, NULL};
    vipStack VIPStack  = {NULL};

    fp = fopen("../input.txt", "r");

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%[^,], %[^,], %[^\n]", info, name, type) == 3) {
            if (strcmp(type, "regular") == 0) {
                enqueue(&RegularQueue, info, name, type);
                printf("Regular client %s lines up at RegularQueue\n", name);
            } else if (strcmp(type, "VIP") == 0) {
                push(&VIPStack, info, name, type);
                printf("VIP client %s lines up at VIPStack\n", name);
            } else {
                continue;
            }
        }
    }

    #ifdef PRINT
        printf("\nRegularQueue:\n");
        printRegularQueue(&RegularQueue);
        printf("\nVIPStack:\n");
        printVIPStack(&VIPStack);
    #endif

    fclose(fp);

    freeNode(RegularQueue.front);
    freeNode(VIPStack.top);

    return 0;
}