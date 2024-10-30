// Hans Cacalda
// October 28, 2024
/* Purpose:  Translates Morse code entered in the CLI to English text 
   by matching each Morse code with a given dictionary. */

   
#include <stdio.h>
// needed for the strcmp()
#include <string.h>

// size needed for the dictionary
#define SIZE 36  

// given Morse code 
const char *morse[SIZE] = {
    "0 -----",
    "1 .----",
    "2 ..---",
    "3 ...--",
    "4 ....-",
    "5 .....",
    "6 -....",
    "7 --...",
    "8 ---..",
    "9 ----.",
    "a .-",
    "b -...",
    "c -.-.",
    "d -..",
    "e .",
    "f ..-.",
    "g --.",
    "h ....",
    "i ..",
    "j .---",
    "k -.-",
    "l .-..",
    "m --",
    "n -.",
    "o ---",
    "p .--.",
    "q --.-",
    "r .-.",
    "s ...",
    "t -",
    "u ..-",
    "v ...-",
    "w .--",
    "x -..-",
    "y -.--",
    "z --.."
};

int main(int argc, char *argv[]) {

    /* 
      2nd argument check, Checks for at least 2 user input within the CLI
      (the first being the program itself)
    */
    if (argc < 2) {
        printf("ERROR: You only typed the executable. Enter the Morse Code on the commandline.\n");
        return 1;  // Exit the program if there aren’t enough arguments
    }

    // for loop function that goes through each Morse code argument 
    for (int argIndex = 1; argIndex < argc; argIndex++) {

        // declaring a variable that will check if there is any match within the given dictionary
        int found = 0; 

        /*
        for loop function to check each Morse code entry in our dictionary and 
        compares the current CLI Morse code argument with each Morse code in the given dictionary
        */
        for (int i = 0; i < SIZE; i++) {

            /* 
               compare the input Morse code with the given dictionary Morse code
               skips the first two characters because they are the character labels
            */
            if (strcmp(argv[argIndex], morse[i] + 2) == 0) {
                // if it matches then print the character
                printf("%c", morse[i][0]);
                found = 1;

                // stops here when it finds the match
                break;  
            }
        }

        // if no match was found, print a 404 error for not found
        if (!found) {
            printf("ERROR 404");  // Error indicator for not found Morse code
        }
    }

    // newline for readability
    printf("\n");

    // ran successfully
    return 0;  
}
