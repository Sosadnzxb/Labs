#include "arrays.h"


void input_size(int* size)
{
	printf("Enter size:");
	while (scanf_s("%d", size) != 1 || *size < 0 || getchar() != '\n')
	{
		printf("Enter size:");
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

void fill_your_array(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Input array: ");
		while (scanf_s("%d", &array[i]) != 1 || getchar() != '\n')
		{
			printf("Input array: ");
			rewind(stdin);
		}
	}
}

void fill_random_array(int* array, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
	}
}

void print_array(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] > 0)
			printf("%d ", array[i]);
	}
	printf("\n");
}

int simple_num(int num)
{
	if (num <= 1)
		return 0;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return 1;
		}
	}
	return 0;
}

void remove_elements(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (simple_num(array[i]))
		{
			printf("%d - Not simple num\n", array[i]);
			for (int j = i; j < size - 1; j++)
			{
				array[j] = array[j + 1];
			}
			size--;
			i--;
		}
	}
	array = (int*)realloc(array, sizeof(int) * size);
	print_array(array, size);
}
