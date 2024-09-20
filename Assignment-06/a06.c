// Author Name: Hans Cacalda
// Date Created: September 17, 2024
// Purpose: Converts any number of your choosing from 0 to 9 to Japanese

// Header file for input/output
#include <stdio.h>

int main(void)
{
    // Variable declaration
    char choice;

    // Program prompt
    printf("This program will display the Japanese word for a number of your choice.\n");

    // Prompts the user to pick a number from 0 to 9
    printf("Enter a number from 0 to 9: ");

    /* Recieves the user's input
       Note: It will only take the FIRST character.*/
    choice = getchar();

    // Consumes the newline character thats left in the input buffer
    getchar();

    // Switch statement that matches the user's choice
    switch (choice)
    {
    // If the user chooses '0'
    case '0':
        // Prompt based on choice
        printf("Japanese Number: '零'|(rei)\n");
        // Exits the switch statement after handling the case
        break;

    // If the user chooses '1'
    case '1':
        // Prompt based on choice
        printf("Japanese Number: '一'|(ichi)\n");
        // Exits the switch statement after handling the case
        break;

    // If the user chooses '2'
    case '2':
        // Prompt based on choice
        printf("Japanese Number: '二'|(ni)\n");
        // Exits the switch statement after handling the case
        break;

    // If the user chooses '3'
    case '3':
        // Prompt based on choice
        printf("Japanese Number: '三'|(san)\n");
        // Exits the switch statement after handling the case
        break;

    // If the user chooses '4'
    case '4':
        // Prompt based on choice
        printf("Japanese Number: '四'|(yon)\n");
        // Exits the switch statement after handling the case
        break;

    // If the user chooses '5'
    case '5':
        // Prompt based on choice
        printf("Japanese Number: '五'|(go)\n");
        // Exits the switch statement after handling the case
        break;

    // If the user chooses '6'
    case '6':
        // Prompt based on choice
        printf("Japanese Number: '六'|(roku)\n");
        // Exits the switch statement after handling the case
        break;

    // If the user chooses '7'
    case '7':
        // Prompt based on choice
        printf("Japanese Number: '七'|(nana)\n");
        // Exits the switch statement after handling the case
        break;

    // If the user chooses '8'
    case '8':
        // Prompt based on choice
        printf("Japanese Number: '八'|(hachi)\n");
        // Exits the switch statement after handling the case
        break;

    // If the user chooses '9'
    case '9':
        // Prompt based on choice
        printf("Japanese Number: '九'|(kyū)\n");
        // Exits the switch statement after handling the case
        break;

    // "Default" execute if none of the cases are chosen
    default:
        // If the user types in a letter rather than a number
        printf("ERROR: '%c' is not a digit in the range of 0-9.\nPlease try again.\n", choice);
        // Exits the switch statement after handling the case
        break;
    }



    // If-else statement version
    /*
        if (choice == '0')
        {
            printf("Japanese Number: '零'|(rei)\n");
        }
        else if (choice == '1')
        {
            printf("Japanese Number: '一'|(ichi)\n");
        }
        else if (choice == '2')
        {
            printf("Japanese Number: '二'|(ni)\n");
        }
        else if (choice == '3')
        {
            printf("Japanese Number: '三'|(san)\n");
        }
        else if (choice == '4')
        {
            printf("Japanese Number: '四'|(yon)\n");
        }
        else if (choice == '5')
        {
            printf("Japanese Number: '五'|(go)\n");
        }
        else if (choice == '6')
        {
            printf("Japanese Number: '六'|(roku)\n");
        }
        else if (choice == '7')
        {
            printf("Japanese Number: '七'|(nana)\n");
        }
        else if (choice == '8')
        {
            printf("Japanese Number: '八'|(hachi)\n");
        }
        else if (choice == '9')
        {
            printf("Japanese Number: '九'|(kyū)\n");
        }
        else
        {
            printf("ERROR: '%c' is not a digit in the range 0-9.\nPlease try again.\n", choice);
        }
     */

    // Indicates a succcesful execution
    return 0;
}
