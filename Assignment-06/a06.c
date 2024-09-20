// Author Name: Hans Cacalda
// Date Created: September 17, 2024
// Purpose: Converts any number of your choosing from 0 to 9 to Japanese

// Header file for input/output
#include <stdio.h>

int main(void)
{
    // Program prompt
    printf("This program will display the Japanese word for a number of your choice.\n");

    // Prompts the user to pick a number from 0 to 9
    printf("Enter a number from 0 to 9: ");

    /* since getchar() grabs the ascii denary number (eg: 2 = 50)
    '0' acts as a way to convert 0 - 9 to be compatable with the switch function.
    eg: getchar() = '2' => 50       '2'(50) - '0'(48) = 2
     */
    int choice = getchar() - '0';
    // Consumes the newline character thats left in the input buffer
    getchar();

    switch (choice)
    {
    case 0:
        printf("Japanese Number: '零'|(rei)\n");
        break;

    case 1:
        printf("Japanese Number: '一'|(ichi)\n");
        break;

    case 2:
        printf("Japanese Number: '二'|(ni)\n");
        break;

    case 3:
        printf("Japanese Number: '三'|(san)\n");
        break;

    case 4:
        printf("Japanese Number: '四'|(yon)\n");
        break;

    case 5:
        printf("Japanese Number: '五'|(go)\n");
        break;

    case 6:
        printf("Japanese Number: '六'|(roku)\n");
        break;

    case 7:
        printf("Japanese Number: '七'|(nana)\n");
        break;

    case 8:
        printf("Japanese Number: '八'|(hachi)\n");
        break;

    case 9:
        printf("Japanese Number: '九'|(kyū)\n");
        break;

    default:
        printf("Please choose from 0 to 9.\n");
        break;
    }

    // If-else statement version
    /*
        if (choice == 0) 
        {
            printf("Japanese Number: '零'|(rei)\n");
        }
        else if (choice == 1)
        {
            printf("Japanese Number: '一'|(ichi)\n");
        }
        else if (choice == 2) 
        {
            printf("Japanese Number: '二'|(ni)\n");
        }
        else if (choice == 3) 
        {
            printf("Japanese Number: '三'|(san)\n");
        }
        else if (choice == 4) 
        {
            printf("Japanese Number: '四'|(yon)\n");
        }
        else if (choice == 5) 
        {
            printf("Japanese Number: '五'|(go)\n");
        }
        else if (choice == 6) 
        {
            printf("Japanese Number: '六'|(roku)\n");
        }
        else if (choice == 7) 
        {
            printf("Japanese Number: '七'|(nana)\n");
        }
        else if (choice == 8) 
        {
            printf("Japanese Number: '八'|(hachi)\n");
        }
        else if (choice == 9) 
        {
            printf("Japanese Number: '九'|(kyū)\n");
        }
        else 
        {
            printf("Please choose from 0 to 9.\n");
        }
     */

    return 0;
};
