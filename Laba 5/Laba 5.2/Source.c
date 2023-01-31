#include"arrays.h"

int main()
{
	int** array = 0;
	int rows = 0, cols = 0, ind_rowmax = 0, choice = 0;
	input_rows_cols(&rows, &cols);
	array = memory(rows, cols);
    choice = choice_0_or_1(choice);
	if (choice == 1) fill_random_array(array, rows, cols);
	else fill_your_array(array, rows, cols);
	print_array(array, rows, cols);
	int ind_max_rows = ind_max_row(array, rows, cols);
	int ind_min_cols = ind_min_col(array, rows, cols, ind_max_rows);
	delete_row(array, rows,cols, ind_max_rows, ind_min_cols);
}
