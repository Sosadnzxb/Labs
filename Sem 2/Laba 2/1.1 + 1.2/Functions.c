#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

void write_file(int num)
{
    FILE* fptr;
    if((fptr = fopen("numbers.txt", "w")) == NULL) {
        perror("Failed to open file");
        return;
    }
    int i = 0;
    int value;
    while (i < num)
    {
        while (scanf_s("%d", &value) != 1 || value < 0 || getchar() != '\n')
        {
            printf("Incorrect input. Try again: ");
            rewind(stdin);
        }
        fprintf(fptr, "%d\n", value);
        i++;
    }
    fclose(fptr);
}

void print_file(int num)
{
    FILE* fptr;
    if ((fptr = fopen("numbers.txt", "r+")) == NULL) {
        perror("Failed to open file");
        return;
    }
    printf("File output:\n");
    int value;
    while (fscanf(fptr, "%d", &value) != EOF) {
        printf("%d  ", value);
    }
    fclose(fptr);
}

void find_max_nums()
{
    FILE* fptr;
    if ((fptr = fopen("numbers.txt", "r")) == NULL) {
        perror("Failed to open file");
        return;
    }
    int temp = INT_MIN;
    int num, count = 1;
    while (fscanf(fptr, "%d", &num) != EOF)
    {
        if (temp == num)
        {
            count++;
        }

        if (temp < num)
        {
            temp = num;
        }
    }
    for (int i = 0; i < count; i++)
        printf("\nNumbers with the maximum value = %d", temp);
}
