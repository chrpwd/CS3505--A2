/* Christian Purdy
 * CS3505
 * A2 Classes & Facades
 * Spiral Class 
*/

#ifndef SPIRAL_H //include guard
#define SPIRAL_H

//INCLUDES
#include <iostream>
#include <math.h>

class Spiral
{
private:
    double CenterX;
    double CenterY;
    double x;
    double y;
    double radius;
    double spiralAngle;
    double textAngle;
    int increment;
    int sConstant;

public:
    double getTextX();
    double getTextY();
    double getSpiralAngle();
    double getTextAngle();
    double getRadius();
    void movePosition();
    Spiral(double, double, double);
    Spiral& operator++();
    Spiral operator++(int);
    friend std::ostream& operator<<(std::ostream&, const Spiral&);
 
};
#endif //end include guard
