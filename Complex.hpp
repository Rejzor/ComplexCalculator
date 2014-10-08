
#ifndef _COMPLEX_HPP_
#define _COMPLEX_HPP_

#include <iostream>

using namespace std;

class Complex
{
public:

	double re, im;

	Complex(); //trzeba zaimplementowac bo kompilator marudzi
	Complex(double real, double imaginary);

	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);

	friend ostream & operator<<(ostream &os, const Complex &c);
};

#endif
