#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

void input_employee(struct Employee* emp) {
    int department_code;
    char last_name[100];
    struct Date hire_date;
    int salary_amount;

    while (1) {
        printf("Department code (1-999): ");
        if (scanf("%d", &department_code) == 1 && department_code >= 1 && department_code <= 999) {
            break;
        }
        printf("Invalid input. Try again.\n");
        while (getchar() != '\n');
    }
    emp->department_code = department_code;

    while (1) {
        printf("Last name (up to 99 characters): ");
        if (scanf("%99s", last_name) == 1 && strlen(last_name) <= 99) {
            break;
        }
        printf("Invalid input. Try again.\n");
        while (getchar() != '\n');
    }
    strcpy(emp->last_name, last_name);

    while (1) {
        printf("Hire date (DD/MM/YYYY): ");
        if (scanf("%d/%d/%d", &hire_date.day, &hire_date.month, &hire_date.year) == 3 &&
            hire_date.day >= 1 && hire_date.day <= 31 &&
            hire_date.month >= 1 && hire_date.month <= 12 &&
            hire_date.year >= 1900 && hire_date.year <= 2100) {
            break;
        }
        printf("Invalid input. Try again.\n");
        while (getchar() != '\n');
    }
    emp->info.hire_date = hire_date;

    while (1) {
        printf("Salary amount (500-5000 (USD/EUR)): ");
        if (scanf("%d", &salary_amount) == 1 && salary_amount >= 500 && salary_amount <= 5000) {
            break;
        }
        printf("Invalid input. Try again.\n");
        while (getchar() != '\n');
    }
    emp->info.salary_amount = salary_amount;
}


void output_employee(struct Employee emp) {
    printf("Department code: %d\n", emp.department_code);
    printf("Last name: %s\n", emp.last_name);

    if (!emp.is_salary) {  // check if hire_date was saved in union
        printf("Hire date: %02d/%02d/%d\n", emp.info.hire_date.day, emp.info.hire_date.month, emp.info.hire_date.year);
    }
    else {  // check if salary_amount was saved in union
        printf("Salary: %d USD/EUR\n", emp.info.salary_amount);
    }
}

void find_min_salary(struct Employee* employees, int n) {
    int min_salary = employees[0].info.salary_amount;
    for (int i = 1; i < n; i++) {
        if (employees[i].info.salary_amount < min_salary) {
            min_salary = employees[i].info.salary_amount;
        }
    }
    printf("Employees with the minimum salary of %d USD/EUR:\n", min_salary);
    for (int i = 0; i < n; i++) {
        if (employees[i].info.salary_amount == min_salary) {
            output_employee(employees[i]);
        }
    }
}

void remove_employees_by_hire_date(struct Employee** employees, int* n, int day, int month, int year) {
    int removed = 0; // флаг для отслеживания того, был ли удален какой-либо сотрудник
    for (int i = 0; i < *n; i++) {
        if ((*employees)[i].info.hire_date.day == (*employees)[i].info.salary_amount && (*employees)[i].info.hire_date.month == month && (*employees)[i].info.hire_date.year == year) {
            // Найден сотрудник с заданной датой приема на работу, удаляем его из массива
            for (int j = i; j < *n - 1; j++) {
                (*employees)[j] = (*employees)[j + 1];
            }
            (*n)--; // уменьшаем размер массива на 1
            *employees = realloc(*employees, (*n) * sizeof(struct Employee)); // освобождаем память, занятую удаленным элементом
            if (*employees == NULL) {
                printf("Memory allocation failed.\n");
                exit(1);
            }
            i--; // возвращаемся на одну позицию назад, чтобы проверить новый элемент, который теперь находится на позиции i
            removed = 1;
        }
    }
    if (removed == 0) {
        printf("No employees with the specified hire date found.\n");
    }
}

