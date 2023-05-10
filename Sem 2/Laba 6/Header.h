#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
    int maxSize;
} Queue;

Queue createQueue(int maxSize);

void enqueue(Queue* queue, char element);

char peek(Queue* queue);

int isEmpty(Queue* queue);

void printQueue(Queue* queue);


