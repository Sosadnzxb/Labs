#define _CRT_SECURE_NO_WARNINGS                         

#include "Header.h"


int main() {                                            //Структура данных
    Stack stack;                                        //LIFO - Last In First Out
    initialize(&stack);                                 //Операции добавления или удаления элементов производятся только на одном конце стека
                                                        //Который называется вершиной.
    int maxSize;
    printf("Enter the maximum stack size (1-100): ");
    while (scanf("%d", &maxSize) != 1 || maxSize < 1 || maxSize > 100) {
        printf("Invalid input. Please enter an integer from 1 to 100: ");
        while (getchar() != '\n'); // Очищаем буфер ввода
    }

    int num;
    printf("Enter the stack elements:\n");
    for (int i = 0; i < maxSize; i++) {
        printf("Element: ", i + 1);
        while (scanf("%d", &num) != 1) {
            printf("\nInvalid input. Please enter an integer: ");
            while (getchar() != '\n'); // Очищаем буфер ввода
        }
        push(&stack, num);
    }

    int sum = getSumOfEvenElements(&stack);
    printf("Sum of even stack elements: %d\n", sum);

    return 0;
}
