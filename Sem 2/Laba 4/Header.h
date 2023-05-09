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

struct Employee {
    int department_code;
    char last_name[100];
    union {
        struct Date hire_date;
        int salary_amount;
    } info;
    int is_salary;
};

void input_employee(struct Employee* emp);

void output_employee(struct Employee emp);

void find_min_salary(struct Employee* employees, int n);

void remove_employees_by_hire_date(struct Employee** employees, int* n, int day, int month, int year);
