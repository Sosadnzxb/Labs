#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack);

int isEmpty(Stack* stack);

int isFull(Stack* stack);

void push(Stack* stack, int element);

int pop(Stack* stack);

int getSumOfEvenElements(Stack* stack);


