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
#define updateEmployee_c
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Declaration of methods*/
void updateEmployeeName();
void updateEmployeeGender();
void updateEmployeeAge();
void updateEmployeeJob();
/*This function will update a selected attribute member of a corresponding selected employee*/
void updateEmployee()
{
    /*For clearing the buffer*/
    char character;
    /*Feature of employee the user wants to modify*/
    char userInput[25];
    int i;
    /*Validation of modification choice entry*/
    while (1)
    {
        printf("\nEnter the employee feature (name, age, gender, job profile) you wish to modify: ");
        /*read a maximum of 100 characters from the stdin stream*/
        if (scanf("%20[^\n]", userInput) == 1)
        {
            printf("You entered: %s\n", userInput);
            for (i = 0; i < strlen(userInput) - 1; i++)
            {
                userInput[i] = (char)tolower(userInput[i]);
            }

            if (strcmp(userInput, "name") == 0 || strcmp(userInput, "gender") == 0 || strcmp(userInput, "age") == 0 || strcmp(userInput, "job profile") == 0)
            {

                break;
            }
        }
        do
        {
            scanf("%c", &character);
        } while (character != '\n');
        printf("\nError - Feature can be either name, age, gender, or job profile. Try again.");
    }

    /*Clear buffer*/
    do
    {
        scanf("%c", &character);
    } while (character != '\n');
    /*If user has chosen to modify one of the following attributes: */
    if (strcmp(userInput, "name") == 0)
    {
        updateEmployeeName();
    }
    else if (strcmp(userInput, "gender") == 0)
    {
        updateEmployeeGender();
    }
    else if (strcmp(userInput, "age") == 0)
    {
        updateEmployeeAge();
    }
    else if (strcmp(userInput, "job profile") == 0)
    {
        updateEmployeeJob();
    }
    else
    {                                                                     /* Unknown Command Case*/
        printf("\nError: Unknown action: %s\nTry again...\n", userInput); /*Print Error Message*/
    }
}

/*This function updates the employee name by processing user input*/
void updateEmployeeName()
{
    /*Name user wants to replace*/
    char userEmployeeName[MAX_NAME_LENGTH + 1];
    /*Old employee name user wants to replace*/
    char oldEmployeeName[MAX_NAME_LENGTH + 1];
    /*New employee name user wants to replace old name with*/
    char newEmployeeName[MAX_NAME_LENGTH + 1];
    /*Pointers to nodes which have the chosen employee names. This will be used to present the list of options and access the node that the user wants to modify*/
    Employee *listOfEmployeeNames[MAX_NUM_EMPLOYEES];
    /*Keeps track of current index of listOfEmployeeNames and used to access the chosen index that holds the pointer to corresponding employee*/
    int index;
    /*Entry the user wants to modify (employee's gender)*/
    int employeeEntryChoice;
    /*For clearing the buffer*/
    char character;
    Employee *ptr;
    int iRC;
    while (1)
    {
        /*Validation of name entry the user wishes to change*/
        while (1)
        {
            printf("\nEnter the name of employee you wish to change: ");
            /*read a maximum of 100 characters from the stdin stream*/
            if (scanf("%100[^\n]", userEmployeeName) == 1)
            {
                do
                {
                    scanf("%c", &character);
                } while (character != '\n');
                break;
            }
            do
            {
                scanf("%c", &character);
            } while (character != '\n');
            printf("\nError - Name of employee must contain alphabets and characters of no more then 100. Try again.");
        }

        /*Name match to the name employee wishes to change*/
        printf("Select which of the following entries you would like to modify: \n");
        ptr = head;
        index = 0;

        while (ptr != NULL)
        {
            if (strncmp(userEmployeeName, ptr->nameOfEmployee, strlen(ptr->nameOfEmployee)) == 0)
            {
                listOfEmployeeNames[index] = ptr;
                printf("\n%d) %s %c %d %s\n", (index + 1), ptr->nameOfEmployee, ptr->employeeGender, ptr->ageOfEmployee, ptr->jobOfEmployee);
                index++;
            }
            ptr = ptr->next;
        }
        if (index == 0)
        {
            printf("\nNo matches for employee names were found in database. Please try again.\n");
            continue;
        }

        while (1)
        {
            iRC = 0;
            printf("Entry choice: ");
            iRC = scanf("%d", &employeeEntryChoice);
            /**/
            if ((iRC == 1) && (employeeEntryChoice <= index && employeeEntryChoice > 0))
            {
                strcpy(oldEmployeeName, listOfEmployeeNames[employeeEntryChoice - 1]->nameOfEmployee);
                do
                {
                    scanf("%c", &character);
                } while (character != '\n');
                while (1)
                {
                    printf("\nEnter new name for employee : ");
                    /*read a maximum of 100 characters from the stdin stream*/
                    if (scanf("%100[^\n]", newEmployeeName) == 1)
                    {
                        do
                        {
                            scanf("%c", &character);
                        } while (character != '\n');
                        break;
                    }
                    do
                    {
                        scanf("%c", &character);
                    } while (character != '\n');
                    printf("\nError - Name of employee must contain alphabets and characters of no more then 100. Try again.");
                }
                strcpy(listOfEmployeeNames[employeeEntryChoice - 1]->nameOfEmployee, newEmployeeName);
                printf("Modified Employee Information (Before: %s): %s %c %d %s\n", oldEmployeeName, listOfEmployeeNames[employeeEntryChoice - 1]->nameOfEmployee, listOfEmployeeNames[employeeEntryChoice - 1]->employeeGender, listOfEmployeeNames[employeeEntryChoice - 1]->ageOfEmployee, listOfEmployeeNames[employeeEntryChoice - 1]->jobOfEmployee);

                return;
            }
            printf("Invalid entry selected. Try again. \n");
            do
            {
                scanf("%c", &character);
            } while (character != '\n');
            continue;
        }
    }
}

/*This function updates the employee gender by processing user input*/
void updateEmployeeGender()
{
    /*Employee's former gender user replaced*/
    char oldEmployeeGender;
    /*For clearing the buffer*/
    char character;
    /*Gender of employee user wants to change- Male (M) or Female (F)*/
    char userEmployeeGender;
    /*Pointers to nodes which have the chosen gender. This will be used to present the list of options and access the node that the user wants to modify*/
    Employee *listOfEmployeeGenders[MAX_NUM_EMPLOYEES];
    /*Keeps track of current index of listOfEmployeeGenders and used to access the chosen index that holds the pointer to corresponding employee*/
    int index;
    /*Entry the user wants to modify (employee's gender)*/
    int employeeEntryChoice;
    /*Pointer for transversing through the linked list*/
    Employee *ptr;
    int iRC;

    while (1)
    {
        iRC = 0;
        printf("\nEnter gender of an employee you wish to change: ");

        iRC = scanf("%c", &userEmployeeGender);
        /*ASCII values for the chars: 'M' = 77; 'm' = 109;'F'= 70;'f'= 102*/
        if ((iRC == 1) && (userEmployeeGender == 77 || userEmployeeGender == 109 || userEmployeeGender == 70 || userEmployeeGender == 102))
        {
            if (userEmployeeGender == 'm')
            {
                userEmployeeGender = toupper('m');
            }
            else if (userEmployeeGender == 'f')
            {
                userEmployeeGender = toupper('f');
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

    /*Name match to the name employee wishes to change*/
    printf("Select which of the following entries you would like to modify: \n");

    ptr = head;
    index = 0;
    while (ptr != NULL)
    {
        if (userEmployeeGender == ptr->employeeGender)
        {
            listOfEmployeeGenders[index] = ptr;
            printf("\n%d) %s %c %d %s\n", (index + 1), ptr->nameOfEmployee, ptr->employeeGender, ptr->ageOfEmployee, ptr->jobOfEmployee);
            index++;
        }
        ptr = ptr->next;
    }

    if (index == 0)
    {
        printf("No matches found. Please try again.\nGoing back to main menu....\n");
        return;
    }

    while (1)
    {
        iRC = 0;
        printf("Entry choice: ");
        iRC = scanf("%d", &employeeEntryChoice);
        /**/
        if ((iRC == 1) && (employeeEntryChoice <= index && employeeEntryChoice > 0))
        {
            oldEmployeeGender = listOfEmployeeGenders[employeeEntryChoice - 1]->employeeGender;
            do
            {
                scanf("%c", &character);
            } while (character != '\n');
            if (listOfEmployeeGenders[employeeEntryChoice - 1]->employeeGender == 'M')
            {
                listOfEmployeeGenders[employeeEntryChoice - 1]->employeeGender = 'F';
            }
            else
            {
                listOfEmployeeGenders[employeeEntryChoice - 1]->employeeGender = 'M';
            }

            printf("Modified Employee Information (Before: %c): %s %c %d %s\n", oldEmployeeGender, listOfEmployeeGenders[employeeEntryChoice - 1]->nameOfEmployee, listOfEmployeeGenders[employeeEntryChoice - 1]->employeeGender, listOfEmployeeGenders[employeeEntryChoice - 1]->ageOfEmployee, listOfEmployeeGenders[employeeEntryChoice - 1]->jobOfEmployee);
            /* do
            {
                scanf("%c", &character);
            } while (character != '\n');*/
            return;
        }
        printf("Invalid entry selected. Try again. \n");
        do
        {
            scanf("%c", &character);
        } while (character != '\n');
        continue;
    }
}

/*This function updates the employee age by processing user input*/
void updateEmployeeAge()
{
    /*For clearing the buffer*/
    char character;
    /*Employee's former age user replaced*/
    int oldEmployeeAge;
    /*Age of employee user wants to change*/
    int userEmployeeAge;
    /*New age of chosen employee*/
    int newEmployeeAge;
    /*Pointers to nodes which have the chosen gender. This will be used to present the list of options and access the node that the user wants to modify*/
    Employee *listOfEmployeeAges[MAX_NUM_EMPLOYEES];
    /*Keeps track of current index of listOfEmployeeAges and used to access the chosen index that holds the pointer to corresponding employee*/
    int index;
    /*Pointer for transversing through the linked list*/
    Employee *ptr;
    /*Entry the user wants to modify (employee's age)*/
    int employeeEntryChoice;

    int iRC;
    while (1)
    {
        while (1)
        {
            iRC = 0;
            printf("\nEnter age of an employee you wish to change: ");

            iRC = scanf("%d", &userEmployeeAge);

            if ((iRC == 1))
            {
                break;
            }
            printf("\nInput not accepted. Please enter a valid age in numericals. ");
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

        /*Age match to the age user wishes to change*/
        printf("Select which of the following entries you would like to modify: \n");
        ptr = head;
        index = 0;
        while (ptr != NULL)
        {
            if (userEmployeeAge == ptr->ageOfEmployee)
            {
                listOfEmployeeAges[index] = ptr;
                printf("\n%d) %s %c %d %s\n", (index + 1), ptr->nameOfEmployee, ptr->employeeGender, ptr->ageOfEmployee, ptr->jobOfEmployee);
                index++;
            }
            ptr = ptr->next;
        }

        if (index == 0)
        {
            printf("No matches found. Please try again.\n");
            continue;
        }

        while (1)
        {
            iRC = 0;
            printf("Entry choice: ");
            iRC = scanf("%d", &employeeEntryChoice);
            /**/
            if ((iRC == 1) && (employeeEntryChoice <= index && employeeEntryChoice > 0))
            {
                oldEmployeeAge = listOfEmployeeAges[employeeEntryChoice - 1]->ageOfEmployee;
                do
                {
                    scanf("%c", &character);
                } while (character != '\n');
                while (1)
                {
                    iRC = 0;
                    printf("\nEnter new age : ");

                    iRC = scanf("%d", &newEmployeeAge);

                    if ((iRC == 1))
                    {
                        break;
                    }
                    printf("\nInput not accepted. Please enter a valid age in numericals. ");
                    do
                    {
                        scanf("%c", &character);
                    } while (character != '\n');
                    continue;
                }
                listOfEmployeeAges[employeeEntryChoice - 1]->ageOfEmployee = newEmployeeAge;
                printf("Modified Employee Information (Before: %d): %s %c %d %s\n", oldEmployeeAge, listOfEmployeeAges[employeeEntryChoice - 1]->nameOfEmployee, listOfEmployeeAges[employeeEntryChoice - 1]->employeeGender, listOfEmployeeAges[employeeEntryChoice - 1]->ageOfEmployee, listOfEmployeeAges[employeeEntryChoice - 1]->jobOfEmployee);
                do
                {
                    scanf("%c", &character);
                } while (character != '\n');
                return;
            }
            printf("Invalid entry selected. Try again. \n");
            do
            {
                scanf("%c", &character);
            } while (character != '\n');
            continue;
        }
    }
}

/*This function updates the employee job profile by processing user input*/

void updateEmployeeJob()
{
    /*Job title user wants to replace*/
    char userJobOfEmployee[MAX_JOB_LENGTH + 1];
    /*Old job title user will replace the new job title with*/
    char oldJobOfEmployee[MAX_JOB_LENGTH + 1];
    /*New job title user will replace the old job title with*/
    char newJobOfEmployee[MAX_JOB_LENGTH + 1];
    /*Pointers to nodes which have the chosen job titles. This will be used to present the list of options and access the node that the user wants to modify*/
    Employee *listOfEmployeeJobTitles[MAX_NUM_EMPLOYEES];
    /*Keeps track of current index of listOfEmployeeJobTitles and used to access the chosen index that holds the pointer to corresponding employee*/
    int index;
    /*Entry the user wants to modify (employee's gender)*/
    int employeeEntryChoice;
    /*For clearing the buffer*/
    char character;
    Employee *ptr;
    int iRC;

    while (1)
    {
        /*Validation of job title the user wishes to change*/
        while (1)
        {
            printf("\nEnter the job title of an employee you wish to change: ");
            /*read a maximum of 100 characters from the stdin stream*/
            if (scanf("%100[^\n]", userJobOfEmployee) == 1)
            {
                do
                {
                    scanf("%c", &character);
                } while (character != '\n');
                break;
            }
            do
            {
                scanf("%c", &character);
            } while (character != '\n');
            printf("\nError - Job title of employee must contain alphabets and characters of no more then 100. Try again.");
        }

        /*Name match to the name employee wishes to change*/
        printf("Select which of the following entries you would like to modify: \n");
        ptr = head;
        index = 0;
        while (ptr != NULL)
        {
            if (strncmp(userJobOfEmployee, ptr->jobOfEmployee, strlen(ptr->jobOfEmployee)) == 0)
            {
                listOfEmployeeJobTitles[index] = ptr;
                printf("\n%d) %s %c %d %s\n", (index + 1), ptr->nameOfEmployee, ptr->employeeGender, ptr->ageOfEmployee, ptr->jobOfEmployee);
                index++;
            }
            ptr = ptr->next;
        }
        if (index == 0)
        {
            printf("\nNo matches for job title found in database. Please try again.\n");
            continue;
        }

        while (1)
        {
            iRC = 0;
            printf("Entry choice: ");
            iRC = scanf("%d", &employeeEntryChoice);
            /**/
            if ((iRC == 1) && (employeeEntryChoice <= index && employeeEntryChoice > 0))
            {
                strcpy(oldJobOfEmployee, listOfEmployeeJobTitles[employeeEntryChoice - 1]->jobOfEmployee);
                do
                {
                    scanf("%c", &character);
                } while (character != '\n');
                while (1)
                {
                    printf("\nEnter new job title : ");
                    /*read a maximum of 100 characters from the stdin stream*/
                    if (scanf("%100[^\n]", newJobOfEmployee) == 1)
                    {
                        do
                        {
                            scanf("%c", &character);
                        } while (character != '\n');
                        break;
                    }
                    do
                    {
                        scanf("%c", &character);
                    } while (character != '\n');
                    printf("\nError - Job title of employee must contain alphabets and characters of no more then 100. Try again.");
                }
                strcpy(listOfEmployeeJobTitles[employeeEntryChoice - 1]->jobOfEmployee, newJobOfEmployee);
                printf("Modified Employee Information (Before: %s): %s %c %d %s\n", oldJobOfEmployee, listOfEmployeeJobTitles[employeeEntryChoice - 1]->nameOfEmployee, listOfEmployeeJobTitles[employeeEntryChoice - 1]->employeeGender, listOfEmployeeJobTitles[employeeEntryChoice - 1]->ageOfEmployee, listOfEmployeeJobTitles[employeeEntryChoice - 1]->jobOfEmployee);

                return;
            }
            printf("Invalid entry selected. Try again. \n");
            do
            {
                scanf("%c", &character);
            } while (character != '\n');
            continue;
        }
    }
}