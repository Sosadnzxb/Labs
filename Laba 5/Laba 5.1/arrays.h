#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void input_size(int* size);

int choice_0_or_1(int choice);

void fill_your_array(int* array, int size);

void fill_random_array(int* array, int size);

void print_array(int* array, int size);

int simple_num(int num);

void remove_elements(int* array, int size);
