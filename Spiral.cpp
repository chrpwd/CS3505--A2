/* Christian Purdy
 * CS3505
 * A2 Classes & Facades
 * Spiral Class Implementation
*/

//INCLUDES
#include "Spiral.h"


// Constructor of Spiral object, asserts that radius given is over 45 degrees
Spiral :: Spiral(double centerX, double centerY, double radiusStart) : CenterX(centerX), CenterY(centerY), x(centerX), y(centerY), radius(radiusStart)
{

	spiralAngle = 180.0;
    	textAngle = 180.0;
    	sConstant = 1000;
	increment = 0;
	if(radiusStart < 0)
    	{
        	radius = 35;
    	}
}

//Returns X Coordinate value
double Spiral::getTextX()
{
    return x;
}

//Returns Y Coordinate value
double Spiral::getTextY()
{
    return y;
}

//Return spiralAngle value
double Spiral::getSpiralAngle()
{
    return spiralAngle;
}

//Return textAngle value
double Spiral::getTextAngle()
{
    return textAngle;
}

//Return textAngle value
double Spiral::getRadius()
{
    return radius;
}


//code snippets from pdfExample, used to change angle and location of x and y values for next char
void Spiral::movePosition()
{
    // textAngle determines the angle of the letter on the page. rad2 is how far
        // around the circle you are. Notice that they are perpendicular and
        // thus not independent.
        //
        // Pay careful attention to what wants radians and what is degrees
        // between haru and spiral and math functions.
        textAngle = (spiralAngle - 90) / 180 * M_PI;
        float rad2 = spiralAngle / 180 * M_PI;
        
        // The position of the character depends on the center point
        // plus the angle and the radius.
        double ratio = radius + increment;

        increment ++;
	
        spiralAngle -= sConstant/ratio;
        x = CenterX + cos(rad2) * ratio;
        y = CenterY + sin(rad2) * ratio;
        
}

// Moves the sprial 'cursor' to the next postion
Spiral& Spiral::operator++() {
    this->movePosition();
    return *this;
}

Spiral Spiral::operator++(int i)
{
    // make a copy for result
    Spiral result(*this);
    //do prefix ++
    ++(*this);
    //return old value         
    return result;  
}

std::ostream& operator<<(std :: ostream& output, Spiral& s)
{
    output << "x value =" << s.getTextX() << " y value =" << s.getTextY() << " angle =" << s.getSpiralAngle() << "radius =" << s.getRadius();
    return output;
}
