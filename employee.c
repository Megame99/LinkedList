/*
* Title: Assignment 2 - Employee Database Implementation
* Course: CST8234 - C Language
* Term: Summer 2021
* Team:
* Student #1: <<< Hanieh Salimian (sali0100@algonquinlive.com) >>>
* Student #2: <<< Megan Machkouri (mach0079@algonquinlive.com) >>>
* Function Name: employee
 * Purpose: Allows declaration and initialization of employees to be added to database
 * Version: 1.0
*/
#define employee_c
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>







/*Declaration of methods*/

void addToDatabase(Employee newEmployee);


/*This function will take in user input for each of the employee attributes to be added to the database*/
void employeeProcessing()
{
    /*Input return code for scanf*/
    int iRC;
    /*For clearing the buffer*/
    char character;
    /*New struct employee is created*/
    Employee employee;

    /*Validation of name entry*/
    while (1)
    {
        printf("\nEnter name: ");
        /*read a maximum of 100 characters from the stdin stream*/
        if (scanf("%100[^\n]", employee.nameOfEmployee) == 1)
        {
            break;
        }

        do
        {
            scanf("%c", &character);
        } while (character != '\n');
        printf("\nError - Name of employee must contain alphabets and characters of no more then 100. Try again.");
    }
    /*Clear buffer*/
    do
    {
        scanf("%c", &character);
    } while (character != '\n');

    /*Validation of gender entry*/
    iRC = 0;
    while (1)
    {
        printf("\nEnter Gender: ");

        iRC = scanf("%c", &employee.employeeGender);
        /*ASCII values for the chars: 'M' = 77; 'm' = 109;'F'= 70;'f'= 102*/
        if ((iRC == 1) && (employee.employeeGender == 77 || employee.employeeGender == 109 || employee.employeeGender == 70 || employee.employeeGender == 102))
        {
            if (employee.employeeGender == 'm')
            {
                employee.employeeGender = toupper('m');
            }
            else if (employee.employeeGender == 'f')
            {
                employee.employeeGender = toupper('f');
            }
            break;
        }
        printf("\nInput not accepted. Please enter a valid gender M or F");
        do
        {
            scanf("%c", &character);
        } while (character != '\n');
        continue;
    }
    /*Clear buffer*/
    do
    {
        scanf("%c", &character);
    } while (character != '\n');

    /*Validation of age entry*/
    iRC = 0;
    while (1)
    {
        printf("\nEnter age: ");
        iRC = scanf("%d", &employee.ageOfEmployee);

        if ((iRC == 0))
        {

            printf("\nInvalid input. Please enter a numerical age");
            do
            {
                scanf("%c", &character);
            } while (character != '\n');
            continue;
        }
        break;
    }
    /*Clear buffer*/
    do
    {
        scanf("%c", &character);
    } while (character != '\n');

    /*Validation of job description input*/
    iRC = 0;

    while (1)
    {
        printf("\nJob Profile: ");
        /*read a maximum of 100 characters from the stdin stream*/
        if (scanf("%100[^\n]", employee.jobOfEmployee) == 1)
        {
            break;
        }
        printf("\nError - Job description of employee must contain alphabets and characters of no more then 100. Try again.\n");
        do
        {
            scanf("%c", &character);
        } while (character != '\n');
    }
    /*Clear buffer*/
    do
    {
        scanf("%c", &character);
    } while (character != '\n');

    addToDatabase(employee);
}
/*This function creates a new employee node, adds attributes passed from employeeProcessing function to the corresponding node members, and prints the attributes of the newly added employee*/
void addToDatabase(Employee newEmployee)
{
    /* Allocate employee node to memory */
    Employee *employee = (Employee *)malloc(sizeof(struct Employee));
    /*When the database is empty, head is initialised and is used to store the new employee's attributes*/
    if (numOfEmployees == 0)
    {
        head = (Employee *)malloc(sizeof(struct Employee));
        strcpy(head->nameOfEmployee, newEmployee.nameOfEmployee);
        head->ageOfEmployee = newEmployee.ageOfEmployee;
        head->employeeGender = newEmployee.employeeGender;
        strcpy(head->jobOfEmployee, newEmployee.jobOfEmployee);
        head->next = NULL;
    }
    /*If the database is populated, the new employee is added to the head of the (database) linked list*/
    else
    {
        /*Assign the employee attributes to the new memory that holds the struct employee*/
        strcpy(employee->nameOfEmployee, newEmployee.nameOfEmployee);
        employee->ageOfEmployee = newEmployee.ageOfEmployee;
        employee->employeeGender = newEmployee.employeeGender;
        strcpy(employee->jobOfEmployee, newEmployee.jobOfEmployee);
        /*Assign the value of head to the next part of inserted Employee node and now newly inserted employee node points to the next node which WAS the beginning node */
        employee->next = head;
        /*Head will now point to the newly inserted node, which is the first node of the LL*/
        head = employee;
    }
    printf("Newly added employee information: %s %c %d %s\n", head->nameOfEmployee, head->employeeGender, head->ageOfEmployee, head->jobOfEmployee);
    numOfEmployees++;
}
/*This function iterates through the linked list database and prints the attributes of each employee node*/
void printDatabase()
{
    /*Assign head point to a temporary variable, which will be used to iterate through the list*/
    Employee *ptr = head;
    printf("\nTotal Number of employees: %d\n", numOfEmployees);
    while (ptr != NULL)
    {
        printf("%s %c %d %s\n", ptr->nameOfEmployee, ptr->employeeGender, ptr->ageOfEmployee, ptr->jobOfEmployee);
        ptr = ptr->next;
    }
}


/*This function iterates through the linked list database and free's memory for each Employee Node.*/
void freeList(){
    Employee *current = head;
    Employee *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
    
}
