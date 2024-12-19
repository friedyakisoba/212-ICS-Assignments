//Hans Cacalda
//December 14 2024
//Puropse: Demonstrates the use of classes and inheritance by modeling a circle and a cylinder. 
//Calculates the area of circles and both the surface area and volume of cylinders based on user input and premade values



#include <iostream>
//for setting decimal precision
#include <iomanip> 

   /*class circle
   contains a radius and methods to set/get the radius and calculate the area */
class Circle {

     //protected so derived classes such as the cylinder can access it directly
protected:
    //holds the radius for the circle
    double radius; 

public:
   /* declares the constant pi for the area calculations
    static since the value will be shared across all circle objects */
    static const double PI; 

    // default constructor, sets the initial radius to 0
    Circle() : radius(0.0) {}

    // constructor with parameter, initializees the radius by a user provided value (whuich is r)
    Circle(double r) : radius(r) {}

    // allows the setting for the circle's radius
    void setRadius(double r) {
        radius = r;
    }

    // returning the current radius, declared as const so it doesnt modify the object
    double getRadius() const {
        return radius;
    }

    //calculate the area of the circle.
    double area() const {
    //  basic area formula = pi * radius * radius || pi * radius^2 
        return PI * radius * radius;
    }
};

// define the constant value of pi, was declared outside becuaase static members must be initialized seperately
const double Circle::PI = 3.1415926;


// class cylinder
// extends the circle class by adding a height and additional methods
class Cylinder : public Circle {
private:
    //holds the height of the cylinder
    double height; 

public:
    // sets both the radius and height to 0
    Cylinder() : Circle(), height(0.0) {}

    // sets both radius and height instantly when the object is created
    Cylinder(double r, double h) : Circle(r), height(h) {}

    // updates the height using setter method
    void setHeight(double h) {
        height = h;
    }

    // retrieves the current value of the height
    double getHeight() const {
        return height;
    }

    /*calculates the surface area of the cylinder
     formula surface area( 2(pi)rh + 2(pi)r^2) = 2 * PI * radius * height + 2 * PI * radius^2*/
    double area() const {
        return 2 * PI * radius * height + 2 * PI * radius * radius;
    }

    /*calculate the volume of the cylinder
     volume((pi)r^2h) = PI * radius^2 * height*/
    double volume() const {
        return PI * radius * radius * height;
    }
};

int main() {

   //output to display numbers in 3 decimal places for better readability
    std::cout << std::fixed << std::setprecision(3); 

    // prompt the user to input the radius of a circle
    // create the circle object
    Circle cir1; 
    // storing the user’s input for radius
    double userRadius; 
    std::cout << "Enter radius for the circle: ";
    // recieve input from the user
    std::cin >> userRadius; 
    // sets the radius of the circle
    cir1.setRadius(userRadius);
    // shows the radius
    std::cout << "Circle cir1: radius= " << cir1.getRadius() << "\n"; 
    // shows the calculated area
    std::cout << "Area of cir1 = " << cir1.area() << "\n\n"; // Display the calculated area.


    // creates another Circle object
    Circle cir2; 
    // ets the radius to 12
    cir2.setRadius(12); 
    std::cout << "Test set and get methods for class Circle:\n";
    // both displays the radius 
    std::cout << "Circle cir2: radius= " << cir2.getRadius() << "\n"; 
    std::cout << "Get data members for cir2: " << cir2.getRadius() << "\n\n"; 


    // creates a cylinder object with radius 20 and height 30
    Cylinder cyl1(20, 30); 
    std::cout << "Test Cylinder class constructor, area(), and volume() functions:\n";
    //shows the radius and height
    std::cout << "Cylinder cyl1: radius= " << cyl1.getRadius() << " height= " << cyl1.getHeight() << "\n"; 
    //shows the surface area and volume
    std::cout << "Area of cyl1 = " << cyl1.area() << "\n"; 
    std::cout << "Volume of cyl1 = " << cyl1.volume() << "\n\n"; 

    // test the set and get methods for another cylinder object
    // creates another cylinder object
    Cylinder cyl2; 
    // sets the radius to 40 and height to 50
    cyl2.setRadius(40); 
    cyl2.setHeight(50); 
    // shows radius and height
    std::cout << "Test set and get methods for class Cylinder:\n";
    std::cout << "Cylinder cyl2: radius= " << cyl2.getRadius() << " height= " << cyl2.getHeight() << "\n"; 
    //shows it one last time
    std::cout << "Get data members for cyl2: " << cyl2.getRadius() << ", " << cyl2.getHeight() << "\n"; 

    //aurightttt
    return 0; 
}
