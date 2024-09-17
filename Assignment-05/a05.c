// 
// 
// 

#include <stdio.h>

#include "getdouble.h"

int main () 
{
    // Variable declarations
    int months;
    int day;
    int year;

    // Program prompt
    printf("This program will calculate your age in days.\n");

    // Prompt that ask for the birthday month
    printf("Enter the month you were born: ");
    // Stores the input in the 'months' variable
    months = getdouble();

    // Prompt that ask for the birthday month
    printf("Enter the day you were born: ");
    // Stores the input in the 'day' variable
    day = getdouble();

    // Prompt that ask for the birthday month
    printf("Enter the year you were born: ");
    // Stores the input in the 'year' variable
    year = getdouble();


    // variable checking area 
    printf("month = %d\n", months);
    printf("days = %d\n", day);
    printf("days = %d\n", year);



    
    return 0;
}