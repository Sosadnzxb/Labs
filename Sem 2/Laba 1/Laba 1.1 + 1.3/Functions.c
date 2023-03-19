#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"


void write_numbers(char** argv, int argc)
{
    FILE* fp;
    if ((fp = fopen(argv[1], "w+")) == NULL) {
        perror("Failed to open file");
        return;
    }
    int nums;
    for (int i = 0; i < argc; i++)
    {
        while (scanf("%d", &nums) != 1 || getchar() != '\n')
        {
            printf("Incorrect input. Try again: ");
            rewind(stdin);
        }
        fwrite(&nums, sizeof(int), 1, fp);
    }
    fclose(fp);
}

void print_file(char** argv)
{
    FILE* fp;
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        perror("Failed to open file");
        return;
    }
    printf("File output:\n");
    int num;
    while (0 != fread(&num, sizeof(int), 1, fp))
    {
        printf("%d ", num);
    }
    printf("\n");
    fclose(fp);
}

int check_input()
{
    int num;
    while (scanf_s("%d", &num) != 1 || getchar() != '\n' || num < 1)
    {
        printf("Incorrect input. Try again: ");
        rewind(stdin);
    }
    return num;
}

void swap_min_max_nums(char** argv)
{
    FILE* fp;
    if ((fp = fopen(argv[1], "r+")) == NULL)
    {
        perror("Failed to open file");
        return;
    }
    int min, max, temp1, temp2, value;
    int imax = 0, imin = 0, i = 0;
    if (fread(&value, sizeof(int), 1, fp) != 1)
    {
        fclose(fp);
        return;
    }
    min = max = value;
    while (fread(&value, sizeof(int), 1, fp) == 1)
    {
        if (value < min) {
            min = value;
        }
        if (value > max) {
            max = value;
        }
    }
    fseek(fp, 0, SEEK_SET);
    printf("Min num = %d", min);
    printf("\nMax num = %d\n", max);
    while (fread(&value, sizeof(int), 1, fp) == 1)
    {
        if (value == min) {
            temp1 = max;
            fseek(fp, -1 * sizeof(int), SEEK_CUR);
            fwrite(&temp1, sizeof(int), 1, fp);
            fseek(fp, 0, SEEK_CUR);
        }
        else if (value == max) {
            temp2 = min;
            fseek(fp, -1 * sizeof(int), SEEK_CUR);
            fwrite(&temp2, sizeof(int), 1, fp);
            fseek(fp, 0, SEEK_CUR);
        }
    }
    fclose(fp);
}


