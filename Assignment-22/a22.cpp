//Hans Cacalda
//Decmber 10 2024

// Lets you create, compare, and perform math operations on complex numbers, which have both a real and an imaginary part.
// It asks you to enter two complex numbers, then shows the results of adding, subtracting, multiplying, dividing, and checks if they are equal or not.

#include <iostream>

//class for complex number and provides functionality to perform
//arithmetic operations, comparisons, and input/output for complex numbers
class Complex {
private:

    // stores the real/imaginary part of the complex number
    double real;
    double imaginary;

public:

    // default constructor initializes the complex number to 0 + 0i
    Complex() {
        real = 0;
        imaginary = 0;
    }

    // constructor to initialize the complex number with specific real/imaginary parts
    Complex(double r, double i) {
        real = r;
        imaginary = i;
    }

    // overloads the input operator (>>) to allow us to input a complex number in the form a+bi
    friend std::istream& operator>>(std::istream& in, Complex& c) {
        char sign, i;
        // reads the real number, signs, imaginary part, and the character i
        in >> c.real >> sign >> c.imaginary >> i;
        // adjusts the imaginary part if the sign is '-'
        if (sign == '-') {
            c.imaginary = -c.imaginary;
        }
        return in;
    }

    // overloads the output operator (<<) to display the complex number in the form a+bi
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        // outputs the real part
        out << c.real;

        // adds the appropriate sign and outputs the imaginary part with i
        if (c.imaginary >= 0) {
            out << "+";
        }
        out << c.imaginary << "i";
        return out;
    }

    // overloads the addition operator to add two complex numbers
    Complex operator+(const Complex& other) {
        Complex temp;

    // adds the real/imaginary parts
        temp.real = real + other.real; 
        temp.imaginary = imaginary + other.imaginary; 
        return temp;
    }

    // overloads the subtraction operator to subtract
    Complex operator-(const Complex& other) {
        Complex temp;

        // subtracts the real/imaginary parts
        temp.real = real - other.real; 
        temp.imaginary = imaginary - other.imaginary; 
        return temp;
    }

    // overloads the multiplication operator to multiply 
    Complex operator*(const Complex& other) {
        Complex temp;

        // formula used: (a+bi)(c+di) = (ac-bd) + (bc+ad)i
        temp.real = real * other.real - imaginary * other.imaginary;
        temp.imaginary = imaginary * other.real + real * other.imaginary;
        return temp;
    }

    // overloads the division operator to divide
    Complex operator/(const Complex& other) {
        Complex temp;

        // calculates the denominator | formula used: (c^2 + d^2)
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        // formula used: [(ac+bd)/(c^2+d^2)] + [(bc-ad)/(c^2+d^2)]i
        temp.real = (real * other.real + imaginary * other.imaginary) / denominator;
        temp.imaginary = (imaginary * other.real - real * other.imaginary) / denominator;
        return temp;
    }

    // overloads the equality operator to check if two are equal
    bool operator==(const Complex& other) {

        // Compares both real and imaginary parts
        return real == other.real && imaginary == other.imaginary; 
    }

    // overloads the inequality operator check if two are not equal
    bool operator!=(const Complex& other) {
        //returns true if not
        return !(real == other.real && imaginary == other.imaginary); 
    }
};

int main() {
    // declares two complex numbers based on/to hold user input
    Complex c1, c2;

    // prompt to input the first complex number in the format a+bi
    std::cout << "Enter a Complex number in the form 'a+bi': ";
    std::cin >> c1;
    // prompt to input the second complex number in the format a+bi
    std::cout << "Enter another Complex number in the form 'a+bi': ";
    std::cin >> c2;

    // declares a complex number to store the result of operations
    Complex result;

    // does addition then display the result
    result = c1 + c2;
    std::cout << "\nTest the + operator:\n";
    std::cout << c1 << " + " << c2 << " = " << result << "\n";

    // does subtraction then display the result
    result = c1 - c2;
    std::cout << "\nTest the - operator:\n";
    std::cout << c1 << " - " << c2 << " = " << result << "\n";

    // does multiplication then display the result
    result = c1 * c2;
    std::cout << "\nTest the * operator:\n";
    std::cout << c1 << " * " << c2 << " = " << result << "\n";

    // does division then display the result
    result = c1 / c2;
    std::cout << "\nTest the / operator:\n";
    std::cout << c1 << " / " << c2 << " = " << result << "\n";

    // checks if the two complex numbers are equal and display the result
    bool isEqual = c1 == c2;
    std::cout << "\nTest the == operator:\n";
    std::cout << c1 << " == " << c2 << " = " << (isEqual ? "true" : "false") << "\n";

    // checks if the two complex numbers are not equal and display the result
    bool isNotEqual = c1 != c2;
    std::cout << "\nTest the != operator:\n";
    std::cout << c1 << " != " << c2 << " = " << (isNotEqual ? "true" : "false") << "\n";

    // ran successfully
    return 0;
}
