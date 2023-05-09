#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

char* read_string() {
    char buffer[100];
    scanf("%99s", buffer);                                  // будет прочитано не более 99 символов, оставляя место для завершающего нулевого символа строки ('\0')
    char* result = (char*)malloc(strlen(buffer) + 1);       // выделяем память для строки
    strcpy(result, buffer);                                 // копируем строку в выделенную память
    return result;                                          // возвращаем указатель на строку
}


void input_employee(struct Employee* emp) {
    int department_code;
    char* last_name;
    struct Date hire_date;
    struct Salary salary;

    do {
        printf("Department code (1-999): ");
        if (scanf("%d", &department_code) != 1 || department_code < 1 || department_code > 999) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
        }
    } while (department_code < 1 || department_code > 999);
    emp->department_code = department_code;

    do {
        printf("Last name (up to 99 characters): ");
        last_name = read_string();
        if (strlen(last_name) > 99) {
            printf("Last name is too long. Try again.\n");
            free(last_name);
        }
    } while (strlen(last_name) > 99);
    emp->last_name = last_name;

    do {
        printf("Hire date (DD/MM/YYYY): ");
        if (scanf("%d/%d/%d", &hire_date.day, &hire_date.month, &hire_date.year) != 3 ||
            hire_date.day < 1 || hire_date.day > 31 ||
            hire_date.month < 1 || hire_date.month > 12 ||
            hire_date.year < 1900 || hire_date.year > 2100) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
        }
    } while (hire_date.day < 1 || hire_date.day > 31 ||
        hire_date.month < 1 || hire_date.month > 12 ||
        hire_date.year < 1900 || hire_date.year > 2100);
    emp->hire_date = hire_date;

    do {
        printf("Salary amount (500-5000 (USD/EUR)): ");
        if (scanf("%d", &salary.amount) != 1 || salary.amount < 500 || salary.amount > 5000) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
        }
    } while (salary.amount < 500 || salary.amount > 5000);
    emp->salary.amount = salary.amount;
}



void output_employee(struct Employee emp) {
    printf("Department code: %d\n", emp.department_code);
    printf("Last name: %s\n", emp.last_name);
    printf("Hire date: %02d/%02d/%d\n", emp.hire_date.day, emp.hire_date.month, emp.hire_date.year);
    printf("Salary: %d USD/EUR\n", emp.salary.amount);
}

struct Employee** find_employees_by_last_name(struct Employee* employees, int n, const char* last_name) {
    struct Employee** matching_employees = (struct Employee**)malloc(n * sizeof(struct Employee*));
    int count = 0;

    if (matching_employees == NULL) {
        printf("Error: could not allocate memory\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        if (employees[i].last_name != NULL && strcmp(employees[i].last_name, last_name) == 0) {   //strcmp используется для сравнения строк и возвращает 0, если строки равны
            matching_employees[count++] = &employees[i];
        }
    }

    if (count == 0) {
        printf("No employees found with last name %s\n", last_name);
        free(matching_employees);
        return NULL;
    }
    else {
        struct Employee** tmp = (struct Employee**)realloc(matching_employees, count * sizeof(struct Employee*));
        if (tmp == NULL) {
            printf("Error: could not reallocate memory\n");
            free(matching_employees);
            return NULL;
        }
        matching_employees = tmp;
        if (matching_employees == NULL) {
            printf("Error: could not reallocate memory\n");
            return NULL;
        }
        printf("Matching employees:\n");
        for (int i = 0; i < count; i++) {
            output_employee(*(matching_employees[i]));
        }
        return matching_employees;
    }
}

struct Employee* delete_employees_below_salary(struct Employee* employees, int* n, int min_salary) {
    // создаем новый массив, в который будут скопированы все оставшиеся структуры Employee
    struct Employee* new_employees = (struct Employee*)calloc((*n), sizeof(struct Employee));
    if (new_employees == NULL) {
        printf("Error: could not allocate memory\n");
        return NULL;
    }
    int new_n = 0;
    // копируем все структуры, у которых зарплата больше либо равна min_salary, в новый массив
    for (int i = 0; i < (*n); i++) {
        if (employees[i].salary.amount >= min_salary) {
            new_employees[new_n++] = employees[i];
        }
        else
        {
            free(employees[i].last_name);
        }
    }
    for (int i = 0; i < new_n; i++) {
        output_employee(new_employees[i]);
    }
    // возвращаем новый массив и его размер
    return realloc(new_employees, new_n * sizeof(struct Employee));
}

void free_employees(struct Employee** employees, int n) {
    for (int i = 0; i < n; i++) {
        free(employees[i]->last_name);
        free(employees[i]);
    }
    free(employees);
}

