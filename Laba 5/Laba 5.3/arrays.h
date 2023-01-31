#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int** memory(int rows, int cols)
{
	int** mass = 0;
	mass = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++)
	{
		mass[i] = (int*)malloc(cols * sizeof(int));
	}
	return mass;
}

void input_rows_cols(int* rows, int* cols)
{
	printf("Enter the number of rows: ");
	while (scanf_s("%d", rows) != 1 || *rows < 0 || getchar() != '\n')
	{
		printf("Enter the number of rows:");
		rewind(stdin);
	}
	printf("Enter the number of columns:");
	while (scanf_s("%d", cols) != 1 || *cols < 0 || getchar() != '\n')
	{
		printf("Enter the number of rows:");
		rewind(stdin);
	}

}

int choice_0_or_1(int choice)
{
	printf("\n0 - Your Input, 1 - Random Input: ");
	while (scanf_s("%d", &choice) == 0 || choice < 0 || choice > 1 || getchar() != '\n')
	{
		printf("\nYou need to write a correct numbers\n");
		rewind(stdin);
	}
	return choice;
}

void fill_your_array(int** array, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
			int j = 0;
			while (scanf_s("%d", &array[i][j]) != 0 && array[i][j] != 0)
			{
				printf("Input element array: ");
				array[i] = (int*)realloc(array[i], (j + 2) * sizeof(int));
				j++;
			}
	}
}

void print_array(int** array, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		int j = 0;
		while (array[i][j] != 0) 
		{
			printf("%4d ", array[i][j]);
			j++;
		}
		printf("\n");
	}
}

int delete_after_element(int element_delete_after)
{
	printf("Delete elements greater than this number: ");
	while (scanf_s("%d", &element_delete_after) == 0 || element_delete_after < 1 || getchar() != '\n')
	{
		printf("\nYou need to write only right numbers\n");
		rewind(stdin);
	}
	return  element_delete_after;
}

void delete_element(int** array, int rows, int element_delete_after) 
{
	for (int i = 0; i < rows; i++)
	{
		int col = 0;
		int j = 0;
		while (array[i][j] != 0)
		{
			col++;
			j++;
		}
		col++;
		for (int k = 0; k < col; k++)
		{
			if (array[i][k] > element_delete_after)
			{
				col--;
				for (int g = k; g < col; g++)
				{
					array[i][g] = array[i][g + 1];
				}
				array[i] = (int*)realloc(array[i], col * sizeof(int));
				k--;
			}
		}
	}
	printf("\nNew Array: \n");
}
