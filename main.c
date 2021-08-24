/*
* Title: Assignment 2 - Employee Database Implementation
* Course: CST8234 - C Language
* Term: Summer 2021
*
* Team:
* Student #1: <<< Hanieh Salimian (sali0100@algonquinlive.com) >>>
* Student #2: <<< Megan Machkouri (mach0079@algonquinlive.com) >>>
* Function Name: main
* Purpose: Allows for program execution and testing.
* Function In parameters: null
* Function Out parameters: 0 or 1 
* Version: 1.0
*/
#define main_c
#include "employee.c"
#include "removeEmployee.c"
#include "updateEmployee.c"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printMenu();

int main()
{
    /*Variable that will be used to process data according to menu option entered*/
  
    char buffer[10];
    char menuChoice;
    /*Input return code for scanf*/
    int menuRC;
 
    /*For clearing the buffer*/
    char character;
    int i;
    do
    {
        /*A while loop that prompts user to enter valid menu option*/

        while (1)
        {
            /*prompt user to enter menu option. */
            printMenu();
            menuRC = scanf("%[^\n]", buffer);
            for ( i = 0; buffer[i] != '\0'; i++)
            {
                menuChoice = buffer[i];
            }
            
            
         
            
            

            if ((menuRC == 1)&&((menuChoice < 53 && menuChoice > 48) || (menuChoice == 81 || menuChoice == 113)))
            {

                printf("You pressed: %c", menuChoice);
                if (menuChoice == 'Q')
                {
                  menuChoice = tolower('Q');
                }
                break;
            }
            do
            {
                scanf("%c", &character);
            } while (character != '\n');
            printf("\nInput not accepted. Please enter a valid option [1-4] or [q]\n");
            continue;

        }
        /*Clear buffer of any remaining data from menu option processing*/
        do
        {
            scanf("%c", &character);
        } while (character != '\n');
        /**/
        switch (menuChoice)
        {
        case '1':
            employeeProcessing();
            break;
        case '2':
            updateEmployee();
            break;
        case '3':
            removeEmployee();
            break;
        case '4':
            printDatabase();
            break;
        case 'q':
        /*TODO: free up memory - maybe make a method that does it all?*/
            freeList();
            printf("\nHave a great day! :) \n");
            return EXIT_SUCCESS;
            break;
        default:
            printf("Unknown Operator: %c\n", menuChoice);
        }
        printf("\nWhat would you like to do next?\n");

    } while (menuChoice != 'q');
    return EXIT_SUCCESS;
}
/*Function that prints main menu onto console*/
void printMenu()
{

    printf("\nPlease choose one of the following options:\n[1] Insert data of another employee \n[2] Modify existing employee information \n[3] Delete an employee's data \n[4] Show all database entries\n [q] Quit \n");
    printf("Please enter action number: ");
}
