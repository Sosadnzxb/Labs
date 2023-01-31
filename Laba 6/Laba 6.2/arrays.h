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
		for (int j = 0; j < cols; j++)
		{
			printf("Input array: ");
			while (scanf_s("%d", &array[i][j]) != 1 || getchar() != '\n')
			{
				printf("Input array: ");
				rewind(stdin);
			}
		}
	}
}

void fill_random_array(int** array, int rows, int cols)
{
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = rand() % 100 - 50 ;
		}
	}
}

void print_array(int** array, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("\t");
			printf("%d", array[i][j]);
		}
		printf("\n");
	}
}

int input_k(int k)
{
	printf("\nEnter a number k (k > 0): ");
	while (scanf_s("%d", &k) == 0 || k <= 0 || getchar() != '\n') {
		printf("\nYou need to write a correct numbers\n");
		rewind(stdin);
	}
	return k;
}

void row_sort(int** array, int cols, int rows, int k) {
	for (int i = 0; i < rows; i++) 
	{
		if ((i + 1) % k == 0)
		{
			printf("Row - %d\n", i + 1);
			int sum1 = 0;
			int sum2 = 0;
			for (int j = 0; j < cols; j++)
			{
				if (i + k < rows) 
				{
					if (array[i][j] > 0)
					{
						sum1 += array[i][j];
					}
					if (array[i + k][j] > 0)
					{
						sum2 += array[i + k][j];
					}

				}
			}
			if (sum1 < sum2)
			{
				int* temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}

	}
}
