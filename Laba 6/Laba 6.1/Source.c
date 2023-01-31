#include"arrays.h"

int main()
{
	int size = 0, choice = 0, start = 0, end = 0, start1 = 0, end1 = 0;
	size = array_size_input(size);
	int* array = calloc(size, sizeof(int));
	choice = choice_0_or_1(choice);
	if (choice == 0) fill_your_array(array, size);
	else fill_random_array(array, size);
	print_array(array, size);
	int first = 0, last = size - 1;
	Hoar_sort_and_time(array,size,first,last,start,end);
	Bouble_sort_time(array,size, start1,end1);
}



