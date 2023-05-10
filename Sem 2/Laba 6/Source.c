#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

int main() {
    int maxSize;                                                          //Структура данных
    printf("Enter the maximum queue size: ");                             //FIFO - First-In-First-Out
    while (scanf("%d", &maxSize) != 1 || maxSize <= 0) {                  //т.е первый элемент, который был добавлен в очередь, будет первым элементом
        printf("Invalid input. Please enter an integer: ");               //который будет удален из очереди.
        while (getchar() != '\n'); // Очищаем буфер ввода
    }

    Queue queue = createQueue(maxSize);

    printf("Enter symbols:\n");
    char input;
    while (scanf(" %c", &input) == 1) {
        if (!isEmpty(&queue) && input == queue.rear->data) {
            printf("Coincidence! Extracted symbol: %c\n", peek(&queue));
        }
        enqueue(&queue, input);

        if (queue.size >= queue.maxSize) {
            printf("Queue is full. Cannot enqueue more elements.\n");
            break;
        }
    }

    printf("Queue after entering symbols:\n");
    printQueue(&queue);

    return 0;
}
