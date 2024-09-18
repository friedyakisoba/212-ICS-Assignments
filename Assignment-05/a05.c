//
//
//

#include <stdio.h>

#include "getdouble.h"

// Conversion function
double birthdayToDays(int day, int month, int year)
{

    // Given function to convert birthdates to days
    double days = (year * 365.25) + ((month - 1) * (365.25 / 12.0)) + day;

    // Returns the total number of day
    return days;
}

int main(void)
{
    // Variable declarations
    int birth_month;
    int birth_day;
    int birth_year;

    // Constants for the current date 
    #define CURRENT_DAY 17
    #define CURRENT_MONTH 9
    #define CURRENT_YEAR 2024

    // Using the 'birthdayToDays' function calculate teh total days of the current date
    double current_days = birthdayToDays(CURRENT_DAY, CURRENT_MONTH, CURRENT_YEAR);

    // Calculate the total days since year 1 using 'birthdayToDays' function
    double birth_days = birthdayToDays(birth_day, birth_month, birth_year);

    // Calculate the age in days by subtracting the birth days from the current days
    double age_in_days = current_days - birth_days;

    // Program prompt
    printf("This program will calculate your age in days.\n");

    // Prompt that ask for the birthday month
    printf("Enter the month you were born: ");
    // Stores the input in the 'months' variable
    birth_month = getdouble();

    // Prompt that ask for the birthday month
    printf("Enter the day you were born: ");
    // Stores the input in the 'day' variable
    birth_day = getdouble();

    // Prompt that ask for the birthday month
    printf("Enter the year you were born: ");
    // Stores the input in the 'year' variable
    birth_year = getdouble();

   
    // Prompts the current date
    printf("Today's date is: %d/%d/%d\n", CURRENT_MONTH, CURRENT_DAY, CURRENT_YEAR);

    // Results of the calculation
    printf("Your age in days is: %.0f\n", age_in_days);

    return 0;
}