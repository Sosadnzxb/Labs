#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

Queue createQueue(int maxSize) {
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    queue.size = 0;
    queue.maxSize = maxSize;
    return queue;
}

void enqueue(Queue* queue, char element) {
    /* if (queue->size >= queue->maxSize) {
         printf("Queue is full. Cannot enqueue more elements.\n");
         return;
     }*/

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

char peek(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return '\0';
    }

    return queue->front->data;
}


int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void printQueue(Queue* queue) {
    Node* current = queue->front;
    printf("Queue: ");

    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}
