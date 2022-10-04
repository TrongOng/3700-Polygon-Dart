//Header file that contains the class definition for the Fraction class
#include <cstdint>
#include <iostream>

#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
	private:
		int32_t num,den;
	public:
		Fraction(int32_t num=0, int32_t den=1);
		~Fraction() = default;

		//rhs = right hand side
		Fraction operator+(Fraction rhs);
		Fraction operator-(Fraction rhs);
		Fraction operator/(Fraction rhs);
		Fraction operator*(Fraction rhs);
		Fraction &operator=(Fraction rhs);

		

		bool operator==(Fraction rhs);
		bool operator!=(Fraction rhs);
		bool operator<=(Fraction rhs);
		bool operator>=(Fraction rhs);
		bool operator<(Fraction rhs);
		bool operator>(Fraction rhs);

		int32_t getNum() {return num;}
		int32_t getDen() {return den;}
};
std::istream &operator>>(std::istream &is, Fraction &f);
std::ostream &operator<<(std::ostream &os, Fraction f);

#endif