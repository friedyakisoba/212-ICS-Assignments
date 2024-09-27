// Hans Cacalda
// September 25, 2024 
// Calculates the escape velocity needed for every planet (except pluto) using if statements, switch, and while functions.
    

// header file for input/output
#include <stdio.h>

// header needed for the sqr() function
#include <math.h>

// display menu function
void printMenu()
{
    // user prompts
    printf("\nEscape Velocity needed For Each Planet\n");
    printf("1. Mercury\n");
    printf("2. Venus\n");
    printf("3. Earth\n");
    printf("4. Mars\n");
    printf("5. Jupiter\n");
    printf("6. Saturn\n");
    printf("7. Uranus\n");
    printf("8. Neptune\n");
    printf("0. EXIT\n");
    printf("Enter your choice (0-8): ");
}

int main(void)
{
    // the universal gravitational constant 
    const double G = 6.67430e-11;

    /* declaration for choice input
       used char for getchar() consitency*/
    char choice;

    // infinite loop until 0 or a valid input is chosen, any other input will start back here
    while (1)
    {
        // calling the printMenu function
        printMenu();

        // input is converted in a char ''
        choice = getchar();
        // consumes the newline character after the choice
        getchar();

        // checks if the user wants to exit or has provided a valid input of 1 through 8)
        if (choice == '0' || (choice >= '1' && choice <= '8'))
        {
            // if so, exits the loop from here
            break;
        }
        // if not, it keeps looping with an error handling and repeats back the character inputed
        else
        {
            printf("ERROR. '%c' is not a valid input.\nPlease enter a number between 0 and 8.\n", choice);
        }
    }

    // if the user chooses. ends it here
    if (choice == '0')
    {
        printf("Exiting...BYE BYE!\n");

        // returns if succesful
        return 0;
    }

    // variable declarations/initialization
    double mass = 0;
    double radius = 0;

    // sets the radius and mass based on the 'choice' input
    switch (choice)
    {
    case '1':
        // mercury
        mass = 3.3011e23;
        radius = 2.4397e6;
        break;
    case '2':
        // venus
        mass = 4.8675e24;
        radius = 6.0518e6;
        break;
    case '3':
        // earth
        mass = 5.972e24;
        radius = 6.371e6;
        break;
    case '4':
        // mars
        mass = 6.4171e23;
        radius = 3.3895e6;
        break;
    case '5':
        // jupiter
        mass = 1.8982e27;
        radius = 6.9911e7;
        break;
    case '6':
        // saturn
        mass = 5.6834e26;
        radius = 5.8232e7;
        break;
    case '7':
        // uranus
        mass = 8.6810e25;
        radius = 2.5362e7;
        break;
    case '8':
        // neptune
        mass = 1.0241e26;
        radius = 2.4622e7;
        break;
    default:
        return 1;
    }

    // calculate escape velocity for the chosen planet
    double escape_velocity = sqrt(2 * G * mass / radius);

    // print the escape velocity with the name of the planet using if-else
    // can use a switch statement, but used 'if' instead to meet the 5 functions quota
    printf("The escape velocity from ");
    if (choice == '1')
    {
        printf("Mercury");
    }
    else if (choice == '2')
    {
        printf("Venus");
    }
    else if (choice == '3')
    {
        printf("Earth");
    }
    else if (choice == '4')
    {
        printf("Mars");
    }
    else if (choice == '5')
    {
        printf("Jupiter");
    }
    else if (choice == '6')
    {
        printf("Saturn");
    }
    else if (choice == '7')
    {
        printf("Uranus");
    }
    else if (choice == '8')
    {
        printf("Neptune");
    }

    // prints the calculated escape velocity
    printf(" is approximately %.6f m/s.\n", escape_velocity);

    // successful 
    return 0;
}
