//Header file thatt contains the class definition for the Point class
#include <cstdint>
#include <iostream>
#include "fraction.h"

#ifndef POINT_H
#define POINT_H
class Point {
    private:
        Fraction x, y;
    public:
    //Input and output of a point in the form (x, y) where x and y are two Fraction objects
        Point(Fraction x = 0, Fraction y = 0);
        ~Point() = default;

        //Add and subtract two points using operator+ and operator-
        Point operator+(Point rhs);
        Point operator-(Point rhs);
        
        //Multiply two points, computing the cross product
        Fraction operator*(Point rhs);
        //Multiply a point by a Fraction, which multiplies both of the point’s coordinates by the given fraction.
        Point operator*(Fraction rhs);
        
        Point &operator=(Point x);
        //Comparison to see if two Point objects are the same or not the same; this should use operator== and operator!=
        bool operator==(Point rhs);
        bool operator!=(Point rhs);

        //Getter methods that return the -coordinate and y-coordinate
        Fraction getX() {
            return x;
        }
        Fraction getY() {
            return y;
        }
    
};
std::istream &operator>>(std::istream &is, Point &p);
std::ostream &operator<<(std::ostream &os, Point p);
#endif