// Hans Cacalda
// October 22 2024
// Purpose: Practice using pointers by storing, printing variable addresses and the update them.

#include <stdio.h>

int main()
{

    // variable declarations
    char letter = 'a';
    int number = 1;
    double decimal = 1.50;

    // Pointer declarations
    // pointer to the character variable
    char *p_letter = &letter;

    // pointer to the integer variable
    int *p_number = &number;

    // pointer to the decimal variable
    double *p_decimal = &decimal;

    // Step 3: Print the addresses of the variables
    printf("Addresses of the variables:\n");
    printf("Address of letter: %p\n", (void *)p_letter);
    printf("Address of number: %p\n", (void *)p_number);
    printf("Address of decimal: %p\n", (void *)p_decimal);

    // Step 4: Print the values of the variables using the pointers
    printf("Values of the variables:\n");
    printf("Letter: %c\n", *p_letter);
    printf("Number: %d\n", *p_number);
    printf("Decimal: %.2f\n", *p_decimal);

    // adding 5 to each variable using the pointers
    *p_letter += 5;
    *p_number += 5;
    *p_decimal += 5;

    //  print the updated values
    printf("Now my program is adding 5 to the dereferenced pointers...\n");
    printf("Letter: %c\n", *p_letter);
    printf("Number: %d\n", *p_number);
    printf("Decimal: %.2f\n", *p_decimal);

    // prints the final values
    printf("Final values of the variables:\n");
    printf("Letter variable: %c\n", letter);
    printf("Number variable: %d\n", number);
    printf("Decimal variable: %.2f\n", decimal);

    // return here if successful
    return 0;
}
