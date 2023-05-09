#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"


int main() {
    int choice;
    int n = 0;
    struct Employee* employees = NULL;

    do {
        printf("\nMenu:\n");
        printf("1. Add employee\n");
        printf("2. Display all employees\n");
        printf("3. Find employees with minimum salary\n");
        printf("4. Remove employees by hire date\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
        }

        switch (choice) {
        case 1:
            // Выделение памяти для нового работника с помощью realloc() и добавление его в массив employees
            n++;
            employees = realloc(employees, n * sizeof(struct Employee));
            if (employees == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }

            printf("Enter employee information:\n");
            input_employee(&employees[n - 1]); // добавление нового работника в конец массива
            break;


        case 2:
            if (employees == NULL) {
                printf("No employees added yet.\n");
            }
            else {
                printf("All employees:\n");
                for (int i = 0; i < n; i++) {
                    output_employee(employees[i]);
                }
            }
            break;

        case 3:
            if (employees == NULL) {
                printf("No employees added yet.\n");
            }
            else {
                printf("Employees with the minimum salary:\n");
                find_min_salary(employees, n);
            }
            break;

        case 4:
            if (employees == NULL) {
                printf("No employees added yet.\n");
            }
            else {
                int day, month, year;
                printf("Enter the hire date to remove employees (DD/MM/YYYY): ");
                while (scanf("%d/%d/%d", &day, &month, &year) != 3 || day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2100) {
                    printf("Invalid input. Please enter a valid date in the format DD/MM/YYYY: ");
                    while (getchar() != '\n');
                }
                remove_employees_by_hire_date(&employees, &n, day, month, year);

            }
            break;

        case 5:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    free(employees);

    return 0;
}
