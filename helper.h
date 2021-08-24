#ifndef helper_h
#define helper_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 ** Header (.H) file for Assignment 2 - Employee Database Implementation
 **
 ** Purpose: Declarations of functions 
 ** @version 1.0
 **
 ** @authors
 ** Student #1: <<< Hanieh Salimian (sali0100@algonquinlive.com) >>>
 ** Student #2: <<< Megan Machkouri (mach0079@algonquinlive.com) >>>
 **/


#define MAX_NAME_LENGTH 100
#define MAX_JOB_LENGTH 100
#define MAX_NUM_EMPLOYEES 150


/* Employee structure*/
typedef struct Employee
{
    /* --Employee details-- */

    /*String employee name*/
    char nameOfEmployee[MAX_NAME_LENGTH + 1];
    /*Gender of employee - Male (M) or Female (F)*/
    char employeeGender;
    /*Age of Employee*/
    int ageOfEmployee;
    /*Job Description of Employee*/
    char jobOfEmployee[MAX_JOB_LENGTH + 1];
    /* pointers to next employee structures in the linked list*/
    struct Employee *next;
} Employee;

/*Number of employees in the database*/
int numOfEmployees = 0;
/*Head pointer to database (Linked-List)*/
Employee *head;

void employeeProcessing();
void printDatabase();
void updateEmployee();
void removeEmployee();
#endif /* helper_h */