#ifndef GETDOUBLE_H
#define GETDOUBLE_H

#include <stdio.h>

// Function to get a double value from the user
double getdouble() {
    double value;
    while (scanf("%lf", &value) != 1) {
        printf("Invalid input. Please enter a valid number: ");
        while (getchar() != '\n'); // clear the buffer
    }
    return value;
}

#endif