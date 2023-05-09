#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int n;

    printf("Enter the number of employees (no more than %d): ", MAX_EMPLOYEES);
    while (scanf("%d", &n) != 1 || n <= 0 || n > MAX_EMPLOYEES) {
        printf("Invalid input. Please enter a number between 1 and %d: ", MAX_EMPLOYEES);
        while (getchar() != '\n');
    }

    for (int i = 0; i < n; i++) {
        printf("Enter employee information %d:\n", i + 1);
        input_employee(&employees[i]);
    }

    for (int i = 0; i < n; i++) {
        output_employee(employees[i]);
    }

    printf("Enter last name to search for: ");
    char* last_name = read_string();

    struct Employee** matching_employees = find_employees_by_last_name(employees, n, last_name);

    if (matching_employees != NULL) {
        free(matching_employees);
    }

    int min_salary = 0;
    printf("Delete employees with a salary below the specified one(no more 500-5000 (USD/EUR)): ");
    while (scanf("%d", &min_salary) != 1 || min_salary < 500 || min_salary > 5000) {
        printf("Invalid input. Please enter a number between 500 and 5000 : ");
        while (getchar() != '\n');
    }

    struct Employee** delete_employee_below_salary = delete_employees_below_salary(employees, &n, min_salary);

    if (delete_employee_below_salary != NULL) {
        free(delete_employee_below_salary);
    }

    free(last_name);
    return 0;
}

