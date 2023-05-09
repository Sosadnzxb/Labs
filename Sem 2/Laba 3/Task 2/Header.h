#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Date {
    int day;
    int month;
    int year;
};

struct Salary {
    int amount;
};

struct Employee {
    int department_code;
    char* last_name;
    struct Date hire_date;
    struct Salary salary;
};

char* read_string();

void input_employee(struct Employee* emp);

void output_employee(struct Employee emp);

struct Employee** find_employees_by_last_name(struct Employee* employees, int n, const char* last_name);

struct Employee* delete_employees_below_salary(struct Employee* employees, int* n, int min_salary);

void free_employees(struct Employee** employees, int n);
