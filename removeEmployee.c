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
#define removeEmployee_c

#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Declaration of methods*/
void deleteNode(Employee *employeeToDelete);
void deleteEmployeeByName();
void deleteEmployeeByGender();
void deleteEmployeeByAge();
void deleteEmployeeByJob();

/*This function will delete an employee from the database*/
void removeEmployee()
{
    /*For clearing the buffer*/
    char character;
    /*Feature of employee the user wants to modify*/
    char userInput[25];
    int i;
    /*Validation of modification choice entry*/
    while (1)
    {
        printf("\nEnter the employee feature (name, age, gender, job profile) you wish to delete: ");
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
    /*If there are no employees in database, prompt user of empty database and return to main menu*/
    if (head == NULL)
    {
        printf("\n Employee Database is empty. \n");
        return;
    }
    /*If user has chosen to delete an employee using one of the following attributes*/
    if (strcmp(userInput, "name") == 0)
    {
        deleteEmployeeByName();
    }
    else if (strcmp(userInput, "gender") == 0)
    {
        deleteEmployeeByGender();
    }
    else if (strcmp(userInput, "age") == 0)
    {
        deleteEmployeeByAge();
    }
    else if (strcmp(userInput, "job profile") == 0)
    {
        deleteEmployeeByJob();
    }
    else
    {                                                                     /* Unknown Command Case*/
        printf("\nError: Unknown action: %s\nTry again...\n", userInput); /*Print Error Message*/
    }
}

/*This function processes the deletion of an employee from database searched and chosen using gender attribute*/
void deleteEmployeeByGender()
{
    /*For clearing the buffer*/
    char character;
    /*Gender of employee user wants to use to search for employee they want to delete*/
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
    /*Ensures that user enters M or F as gender queries. If not user is prompted to try again*/
    while (1)
    {
        iRC = 0;
        printf("\nEnter gender of an employee you wish to delete: ");

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

    /*Gender match to the corresponding employees the user wishes to delete*/
    printf("Select which of the following entries you would like to delete: \n");
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
    /*If no matches are found then user is prompted about it and the program returns to main menu*/
    if (index == 0)
    {
        printf("No matches found. Please try again.\nGoing back to main menu....\n");
        return;
    }
    /*User selects which employee they want to delete*/
    while (1)
    {
        iRC = 0;
        printf("Entry choice: ");
        iRC = scanf("%d", &employeeEntryChoice);
        /**/
        if ((iRC == 1) && (employeeEntryChoice <= index && employeeEntryChoice > 0))
        {
            deleteNode(listOfEmployeeGenders[employeeEntryChoice - 1]);
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
/*This function processes the deletion of an employee from database searched and chosen using age attribute*/
void deleteEmployeeByAge()
{
    /*For clearing the buffer*/
    char character;
    /*Age of employee user wants to delete*/
    int userEmployeeAge;
    /*Pointers to nodes which have the chosen age. This will be used to present the list of options and access the node that the user wants to delete*/
    Employee *listOfEmployeeAges[MAX_NUM_EMPLOYEES];
    /*Keeps track of current index of listOfEmployeeAges and used to access the chosen index that holds the pointer to corresponding employee*/
    int index;
    /*Pointer for transversing through the linked list*/
    Employee *ptr;
    /*Entry the user wants to delete (employee's age)*/
    int iRC, employeeEntryChoice;
    /*Ensures that user enters an integer value as age for searching an employee. If not user is prompted to try again*/
    while (1)
    {
        iRC = 0;
        printf("\nEnter age of an employee you wish to delete: ");

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

    /*Age match to the age user wishes to delete*/
    printf("Select which of the following entries you would like to delete: \n");
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
    /*If no matches are found then user is prompted about it and the program returns to main menu*/
    if (index == 0)
    {
        printf("No matches found. Please try again.\n");
        return;
    }
    /*User can now enter /select which employee they want to delete*/
    while (1)
    {
        iRC = 0;
        printf("Entry choice: ");
        iRC = scanf("%d", &employeeEntryChoice);
        /**/
        if ((iRC == 1) && (employeeEntryChoice <= index && employeeEntryChoice > 0))
        {
            deleteNode(listOfEmployeeAges[employeeEntryChoice - 1]);
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
/*This function deletes an employee searched for based on their job profile*/
void deleteEmployeeByJob()
{
    /*Job title user wants to replace*/
    char userJobOfEmployee[MAX_JOB_LENGTH + 1];
    /*Pointers to nodes which have the chosen job titles. This will be used to present the list of options and access the node that the user wants to modify*/
    Employee *listOfEmployeeJobTitles[MAX_NUM_EMPLOYEES];
    /*Keeps track of current index of listOfEmployeeJobTitles and used to access the chosen index that holds the pointer to corresponding employee*/
    int index;
    /*Entry the user wants to delete (based on employee's job profile)*/
    int employeeEntryChoice, iRC;
    /*For clearing the buffer*/
    char character;
    /*For iteration through list*/
    Employee *ptr;

    /*Validation of job title the user wishes to delete*/
    while (1)
    {
        printf("\nEnter the job title of an employee you wish to delete: ");
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

    /*Job profile match to the employee's job the user wishes to delete*/
    printf("Select which of the following entries you would like to delete: \n");
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
    /*If no matches are found then user is prompted about it and the program returns to main menu*/
    if (index == 0)
    {
        printf("\nNo matches for job title found in database. Please try again.\n");
        return;
    }
    /*User can now select and enter which employee they want to delete*/
    while (1)
    {
        iRC = 0;
        printf("Entry choice: ");
        iRC = scanf("%d", &employeeEntryChoice);
        /*Input validation for entry choices*/
        if ((iRC == 1) && (employeeEntryChoice <= index && employeeEntryChoice > 0))
        {
            deleteNode(listOfEmployeeJobTitles[employeeEntryChoice - 1]);
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

/*This function processes the deletion of an employee from database searched and chosen using name attribute*/
void deleteEmployeeByName()
{
    /*Pointers to nodes which have the chosen employee names. This will be used to present the list of options and access the node that the user wants to delete*/
    Employee *listOfEmployeeNames[MAX_NUM_EMPLOYEES];
    /*Keeps track of current index of listOfNames and used to access the chosen index that holds the pointer to corresponding employee*/
    int index;
    /*Name of employee the user wants to delete*/
    char userEmployeeName[MAX_NAME_LENGTH + 1];
    /*For clearing the buffer*/
    char character;
    /*Validation of name entry the user wishes to change*/
    int iRC, employeeEntryChoice;
    Employee *ptr;
    /*User is prompted to enter the name of employee they wish to delete. Input validation ensures that user doesn't exceed the expected length for employee name*/
    while (1)
    {
        printf("\nEnter the name of employee you wish to delete: ");
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
    /*Name match to the name employee wishes to delete*/
    printf("Select which of the following entries you would like to delete: \n");
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
            deleteNode(listOfEmployeeNames[employeeEntryChoice - 1]);
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
/*This function uses the pointer to selected node to be deleted and removes the employee node of the corresponding employee the user wishes to delete from database*/
void deleteNode(Employee *employeeToDelete)
{
    /*Both the following variables utilize the head pointer since we will start from the beginning of the list for deletion processing*/
    /*Head node is stored as a temp variable. This will point EXACTLY TO the node that needs to be deleted from the list*/
    Employee *temp = head;
    /*Another variable that stores the head node only this time it will point to the node that is positioned BEFORE the node that needs to be deleted*/
    Employee *prev = head;
    char choice;
    while (1)
            {
                while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
                printf("\n Is this the employee you wish to discard from database. Please confirm [Y/N] \n");
                printf("%s %c %d %s \n", employeeToDelete->nameOfEmployee, employeeToDelete->employeeGender, employeeToDelete->ageOfEmployee, employeeToDelete->jobOfEmployee);
                scanf("%c", &choice);
                while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
                
                if (choice == 89 || choice == 121)
                {
                    break;
                }
                else if(choice == 110 || choice == 78){
                    printf("\nEntry was not deleted.\n");
                    return;
                }
            
            }

    


    /* If head node itself holds the key to be deleted*/
    if (temp != NULL && (strncmp(temp->nameOfEmployee, employeeToDelete->nameOfEmployee, strlen(employeeToDelete->nameOfEmployee)) == 0) &&
        (strncmp(temp->jobOfEmployee, employeeToDelete->jobOfEmployee, strlen(employeeToDelete->jobOfEmployee)) == 0) &&
        (temp->ageOfEmployee == employeeToDelete->ageOfEmployee) && (temp->employeeGender == employeeToDelete->employeeGender))
    {
        head = temp->next; /* Head pointer moved to the next node*/
        free(temp);        /* Free old node the head node was pointing to*/
        numOfEmployees--;
        printf("\nEntry deleted successfully\n");
        return;
    }
    /*If node to be deleted isn't the first node*/
    while (prev->next != NULL)
    {
        /* If previous node's next node is the one to be deleted....*/
        if ((strncmp(prev->next->nameOfEmployee, employeeToDelete->nameOfEmployee, strlen(employeeToDelete->nameOfEmployee)) == 0) &&
            (strncmp(prev->next->jobOfEmployee, employeeToDelete->jobOfEmployee, strlen(employeeToDelete->jobOfEmployee)) == 0) &&
            (prev->next->ageOfEmployee == employeeToDelete->ageOfEmployee) && (prev->next->employeeGender == employeeToDelete->employeeGender))
        {
            temp = prev->next;
            /*node will be disconnected from the linked list.*/
            prev->next = prev->next->next;
            free(temp);
            printf("\nEntry deleted successfully\n");
            numOfEmployees--;
            return;
        }
        /*Otherwise, move the previous node and proceed*/
        else
            prev = prev->next;
    }
    
}