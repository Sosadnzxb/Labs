#include"arrays.h"

int main()
{
	int** array = 0;
	int rows = 0, cols = 0, ind_rowmax = 0, choice = 0, k = 0;
	input_rows_cols(&rows, &cols);
	array = memory(rows, cols);
	choice = choice_0_or_1(choice);
	if (choice == 1) fill_random_array(array, rows, cols);
	else fill_your_array(array, rows, cols);
	print_array(array, rows, cols);
	k = input_k(k);
	row_sort(array, rows, cols, k);
	print_array(array, rows, cols);
}
