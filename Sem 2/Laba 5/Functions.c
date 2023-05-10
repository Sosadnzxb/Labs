#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Error: Stack is full\n");
        return;
    }
    stack->data[++stack->top] = element;
}

//int pop(Stack* stack) {
//    if (isEmpty(stack)) {
//        printf("Error: Stack is empty\n");
//        return -1;
//    }
//    return stack->data[stack->top--];
//}

int getSumOfEvenElements(Stack* stack) {
    int sum = 0;
    for (int i = 0; i <= stack->top; i++) {
        if (stack->data[i] % 2 == 0) {
            sum += stack->data[i];
        }
    }
    return sum;
}
