


#include <stdio.h>
#include <stdlib.h>

// Prototypes for basic operations
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }

/*  
Division check and error handling
Returns 0 if y is zero to avoid "division by zero errors"
*/
int divide(int x, int y) { return y != 0 ? x / y : 0; } 



int main(int argc, char *argv[]) {

    /* 
     Confirmation function to make sure we got exactly 4 argumetns
     Prints an error message if there is no 4 argumetns and exits
     */
    if (argc != 4) {
        printf("ERROR: You have to enter 4 command line arguments for the calculator.\n");
        return 1;
    }

    /*
    Confirms that the argument to be a single digit integer and checks it using ASCII values 
    hence '0' and '9' 
    If it is not a digit, another error handling is in place and exits.
     */ 
    if (argv[1][0] < '0' || argv[1][0] > '9' || argv[1][1] != '\0') {
        printf("ERROR: The second command line argument should be an integer 0-9.\n");
        return 1;
    }

    /*
    Confirms the argument for the operator and checks it by using ASCII values  
    Another error handling is in place and exits.
     */
    if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '.' && argv[2][0] != '/') {
        printf("ERROR: The third command line argument should be a +, -, ., or / operator.\n");
        return 1;
    }

    /* 
    Similar to the function above function confirms that the argument to be a single digit integer by using its using ASCII values 
    Another error handling is in place and exits.
     */
    if (argv[3][0] < '0' || argv[3][0] > '9' || argv[3][1] != '\0') {
        printf("ERROR: The fourth command line argument should be an integer 0-9.\n");
        return 1;
    }


    // Converts the integer arguments from characters to integers by using the ASCII value 48 ('0')
    int number1 = argv[1][0] - '0';
    int number2 = argv[3][0] - '0';

    /*  Step 6: Convert operator to an index by using the ASCII values for '+', '-', '.', and '/' 
        This allows mapping the an index to the function array
        */ 
    int index = argv[2][0] - '+';  



    // Given array function from the instructions
    int (*operations[5])(int, int) = { add, NULL, sub, mul, divide };


    //Call the function by using the array to select the right operator and then print the result
    int result = operations[index](number1, number2);
    printf("%d %c %d = %d\n", number1, argv[2][0], number2, result);


    // code ran successfully 
    return 0;
}
