//File containing the Point class methods (functions)
//converting to fractional points
#include "point.h"

// Point p1(a,b)
Point::Point(Fraction xCoord, Fraction yCoord) {

    x = xCoord;
    y = yCoord;
}

Point Point::operator+(Point rhs) {
    Fraction s, t;
    s = x + rhs.x;
    t = y + rhs.y;
    
    return Point(s,t);
}
Point Point::operator-(Point rhs) {
    Fraction s, t;
    s = x - rhs.x;
    t = y - rhs.y;
    
    return Point(s,t);
}
Fraction Point::operator*(Point rhs) {
    Fraction s;
    s = (x*rhs.y)-(y*rhs.x);
    return s;
}
Point Point::operator*(Fraction rhs) {
    Fraction s,t;
    s = x*rhs;
    t = y*rhs;
    return Point(s,t);
}
Point &Point::operator=(Point rhs) {
	x = rhs.x;
	y = rhs.y;
	return *this;
} 
bool Point::operator==(Point rhs) {
    return x == rhs.x && y == rhs.y;
}
bool Point::operator!=(Point rhs) {
    return x != rhs.x || y != rhs.y;
}

std::istream &operator>>(std::istream &is, Point &p) {
    Fraction x , y;
    char comma;
    
    is >> x >> y;
    p = Point(x,y);
    return is;
}
std::ostream &operator<<(std::ostream &os, Point p) {
    os << "(" << p.getX() << "," << p.getY() << ")";
    return os;
}

