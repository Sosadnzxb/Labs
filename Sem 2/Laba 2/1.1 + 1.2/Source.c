#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

int main()
{
    FILE* fptr;
    int num;
    printf("Enter number of elements: ");
    while (scanf("%d", &num) != 1 || num < 0 || getchar() != '\n')
    {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    write_file(num);
    print_file(num);
    find_max_nums();
    return 0;
}
