//
//
//
#include <stdio.h>

#include "getdouble.h"

int main(int argc, char const *argv[])
{
    char character = 'a';
    double number = 0.0;

    printf("Please enter the first letter: ");
    character = getchar();
    getchar();
    printf("Your first letter is: '%c'\n", character);

    printf("Please enter the second letter: ");
    character = getchar();
    getchar();
    printf("Your second letter is: '%c'\n", character);



    printf("Please enter the first number: ");
    number = getdouble();
    printf("The number is: %f\n", number);

    printf("Please enter the second number: ");
    number = getdouble();
    printf("The number is: %f\n", number);
    return 0;
}
