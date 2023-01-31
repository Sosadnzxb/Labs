#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

void Hoar_sort(int* array, int first, int last)
{
	int i = first, j = last;
	double tmp, x = array[(first + last) / 2];

	do {
		while (array[i] < x)
			i++;
		while (array[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		Hoar_sort(array, i, last);
	if (first < j)
		Hoar_sort(array, first, j);
}

void Bouble_sort(int* array, int size)
{
	int i, j, buf;
	for (i = 0; i < size -  1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1]) 
			{
				buf = array[j];
				array[j] = array[j + 1];
				array[j + 1] = buf;
			}
		}
	}
}

int array_size_input(int size) 
{
	printf("Enter a size of the array: ");
	while (scanf_s("%d", &size) == 0 || size < 1 || getchar() != '\n') {
		printf("\nYou need to write a right numbers\n");
		rewind(stdin);
	}
	return size;
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
		array[i] = rand() % 10000;
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


void Hoar_sort_and_time(int* array, int size, int first, int last, int start, int end) 
{
	start = clock();
	Hoar_sort(array, first, last);
	end = clock();
	printf("\nNew array: \n");
	print_array(array, size);
	printf("\nHoar sort time: %d\n", end - start);                                                                              //    (...)/CLOCKS_PER_SEC
}


void Bouble_sort_time(int* array, int size, int start1, int end1) 
{
	start1 = clock();
	Bouble_sort(array, size);
	end1 = clock();
	printf("\nBouble sort time: %d\n", end1 - start1);
}
