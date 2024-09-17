// Author Name: Hans Cacalda
// Date Created: September 13, 2024
// Purpose: Prompts the user to input a letter and repeats it back to them, as well as ask the user 
// for a number and converts it to a floating double format. 


#include <stdio.h>

#include "getdouble.h"

int main()
{
    // Declaring our variables first
    char character = 'a';
    double number = 0.0;

    // a prompt that asks for the first letter
    printf("Please enter the first letter: ");
    // stores the input letter to the 'character' variable
    character = getchar();
    // consumes the new line so it avoids breaking
    getchar();
    // result of the first letter
    printf("Your first letter is: '%c'\n", character);

    // a prompt that asks  for the second letter
    printf("Please  enter the second letter: ");
    character = getchar();
    // consumes the new line so it avoids breaking
    getchar();
    // result of the second letter
    printf("Your second letter is: '%c'\n", character);


    // prompt that asks for the first number 
    printf("Please enter the first number: ");
    // stores the input in the 'number' variable and converts it as a decimal
    number = getdouble();
    // result of the first number input
    printf("The number is: %f\n", number);

    // prompt that asks for the first number 
    printf("Please enter the second number: ");
    // stores the input in the 'number' variable and converts it as a decimal
    number = getdouble();
    // result of the second number input
    printf("The number is: %f\n", number);

    // returns here if ran correctly 
    return 0;
}
