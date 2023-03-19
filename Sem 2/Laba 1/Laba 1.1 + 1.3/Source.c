#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"


int main(int argc, char** argv)
{
    printf("Enter number of elements: ");
    int num = check_input();
    write_numbers(argv, num);
    print_file(argv);
    swap_min_max_nums(argv);
    print_file(argv);
    return 0;
}
