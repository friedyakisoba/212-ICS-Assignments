//Hans Cacalda
//Decemer 10 2024
// Creates and manipulates complex numbers, which have both real and imaginary parts

#include <iostream> 

//  a class to represent complex numbers
class Complex {
public:
    // a public member variable to store the real/imaginary part of the complex number
    double real;
    double imaginary;

    // constructor that initializes a complex object with specified real/imaginary parts
    Complex(double r, double i) {

        // sets the real/imaginary part.
        real = r;
        imaginary = i;
    }

    // our default constructor that initializes a Complex object with real/imaginary parts set to 0
    Complex() {

        // Default values for the real/imaginary part
        real = 0.0;
        imaginary = 0.0;
    }

    // copy constructor that reates a new complex object as a copy of an existing complex object
    Complex(const Complex& c) {

        // copies the real/imaginary part from the provided object.
        real = c.real;
        imaginary = c.imaginary;
    }

    // destructor, called automatically when a complex object is destroyed
    ~Complex() {
        // prompts a message indicating the object is being destroyed.
        std::cout << "Destructor for: (" << real << " + " << imaginary << "i)" << std::endl;
    }

    // adds the current complex object to another complex object and returns the result
    Complex add(Complex c) {

        // creates a new object to store the result
        Complex result;
        // adds the real parts.
        result.real = real + c.real;
        //aAdds the imaginary parts.
        result.imaginary = imaginary + c.imaginary;
        // returns the resulting complex object 
        return result;
    }

    // subtracts another object from the current omplex object and returns the result
    Complex subtract(Complex c) {
    
        // createst new object => subtracts real/imaginary parts => returns the resulting object
        Complex result;
        result.real = real - c.real;
        result.imaginary = imaginary - c.imaginary;
        return result;
    }

    // multiplies the current object
    Complex multiply(Complex c) {

        // createst new object => multplies real/imaginary parts => returns the resulting object
        Complex result;
        result.real = (real * c.real) - (imaginary * c.imaginary);
        result.imaginary = (real * c.imaginary) + (imaginary * c.real);
        return result;
    }

    // divides the current object 
    Complex divide(Complex c) {

        // createst new object 
        Complex result;
        // calculates the denominator of the division.
        double denominator = (c.real * c.real) + (c.imaginary * c.imaginary);
        // calculates the real part of the quotient.
        result.real = ((real * c.real) + (imaginary * c.imaginary)) / denominator;
        // calculates the imaginary part of the quotient.
        result.imaginary = ((imaginary * c.real) - (real * c.imaginary)) / denominator;
        // returns the resulting object.
        return result;
    }

    // prints complex number in a readable format.
    void print() {

        // prints in the format of: real + imaginaryi
        std::cout << "(" << real << " + " << imaginary << "i)";
    }
};

int main() {

    // create an object using the constructor
    Complex c1(3.3, 4.7);

    // message for constructor + value of C1
    std::cout << "Testing constructor:" << std::endl;
    std::cout << "c1 = ";
    c1.print();
    std::cout << std::endl;

    // creates the object => prints a testing message for default construct => prints the value of C2
    Complex c2;
    std::cout << "Testing default constructor:" << std::endl;
    std::cout << "c2 = ";
    c2.print();
    std::cout << std::endl;

    // creates the object => prints a testing message for default construct => prints the value of C3
    Complex c3 = c1;
    std::cout << "Testing copy constructor:" << std::endl;
    std::cout << "c3 = ";
    c3.print();
    std::cout << std::endl;

    // tests the addition of two objects
    Complex c4 = c1.add(c3);
    // print message for addition.
    std::cout << "Testing add function:" << std::endl;
    // print the value of c1
    c1.print();
    // print the addition symbol
    std::cout << " + ";
    // print the value of c3
    c3.print();
    // print the equals symbol
    std::cout << " = ";
    // print the result of the addition
    c4.print();
    std::cout << std::endl;

    // tests the subtraction of two objects
    Complex c5 = c1.subtract(c3);
    // print testing message for subtraction.
    std::cout << "Testing subtract function:" << std::endl;
    // print the value of c1.
    c1.print();
    // print the subtraction symbol
    std::cout << " - ";
    // print the value of c3
    c3.print();
    // print the equals symbol
    std::cout << " = ";
    // print the result of the subtraction
    c5.print();
    std::cout << std::endl;

    // tests the multiplication of two objects
    Complex c6 = c1.multiply(c3);
    // print testing message for multiplication
    std::cout << "Testing multiply function:" << std::endl;
    // print the value of c1
    c1.print();
    // print the multiplication symbol
    std::cout << " * ";
    // print the value of c3
    c3.print();
    // print the equals symbol
    std::cout << " = ";
    // print the result of the multiplication
    c6.print();
    std::cout << std::endl;

    // tests the division of two objects
    Complex c7 = c1.divide(c3);
    // print testing message for division
    std::cout << "Testing divide function:" << std::endl;
    // print the value of c1.
    c1.print();
    // print the division symbol
    std::cout << " / ";
    // print the value of c3
    c3.print();
    // print the equals symbol
    std::cout << " = ";
    // print the result of the division
    c7.print();
    std::cout << std::endl;

    // we gud
    return 0;
}
