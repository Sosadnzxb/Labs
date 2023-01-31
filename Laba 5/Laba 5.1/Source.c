#include"arrays.h"


int main()
{
	int size = 0, choice = 0;
	input_size(&size);
	int* array = calloc(size, sizeof(int));
	choice = choice_0_or_1(choice);
	if (choice == 1) fill_random_array(array, size);
	else fill_your_array(array, size);
	print_array(array, size);
	remove_elements(array, size);
}
