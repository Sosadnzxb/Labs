#include "arrays.h"

int main(int argc, char** argv)
{
	char** string = (char**)calloc(argc - 1, sizeof(char*));
	memory(string, argc, argv);
	copy(string, argc, argv);
	output(string, argc - 1);
	quick_sort(string, 0, (argc - 1 - 1));
	output(string, argc - 1);
}
