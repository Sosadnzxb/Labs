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
			array[i][j] = rand() % 100;
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

int ind_max_row(int** array, int rows, int cols)
{
	int rowmax = 0, ind_rowmax = 0;
	rowmax = array[0][0];
	for (int j = 0; j < cols; j++)
	{
		for (int i = 0;i < rows; i++)
		{
			if (rowmax < array[i][j])
			{
				rowmax = array[i][j];
				ind_rowmax = i;
			}
		}	
	}
	printf("ind_rowmax = %d\n", ind_rowmax);
	return ind_rowmax;
}

int ind_min_col(int** array,int rows, int cols, int ind_rowmax)
{
	int ind_min_cols = 0, colmin;
	colmin = array[ind_rowmax][0];
	for (int k = 0; k < rows; k++)
	{
		if (colmin > array[ind_rowmax][k])
			{
			colmin = array[ind_rowmax][k];
				ind_min_cols = k;
			}
	}
	printf("ind_mincol = %d", ind_min_cols);
	return ind_min_cols;
}

void delete_row(int** array,int rows,int cols,int ind_rowmax, int ind_min_cols)
{
	if (ind_rowmax == ind_min_cols)
	{
		for (int i = ind_rowmax; i < rows - 1; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				array[i][j] = array[i + 1][j];
			}
			array = (int**)realloc(array, rows * sizeof(int*));
		}
		rows--;
		printf("\nNew array: \n");
		print_array(array, rows, cols);
	}
	if (ind_rowmax != ind_min_cols)
		printf("\nSaddle point wasn't find\n");
}
