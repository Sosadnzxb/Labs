#include"arrays.h"

int main()
{
	int** array = 0;
	int rows = 0, cols = 0, element_delete_after = 0;
	input_rows_cols(&rows, &cols);
	array = memory(rows, cols);
	element_delete_after = delete_after_element(element_delete_after);
	fill_your_array(array, rows, cols);
	print_array(array, rows, cols);
	delete_element(array, rows, element_delete_after);
    print_array(array, rows, cols);
}
