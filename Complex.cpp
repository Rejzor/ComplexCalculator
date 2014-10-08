#include "Complex.hpp"

using namespace std;

Complex::Complex()
{
	re = 0;
	im = 0;
}

Complex::Complex(double real, double imag)
{
	re = real;
	im = imag;
}

Complex Complex::operator+(const Complex& c)
{
	return Complex(re + c.re, im + c.im);
}

Complex Complex::operator-(const Complex& c)
{
	return Complex(re - c.re, im - c.im);
}

Complex Complex::operator*(const Complex& c)
{
	//(a+bi) * (c+di) = (ac-bd) + (bc+ad)i.  //wzor z wikipedii
	return Complex(re * c.re - im * c.im, im * c.re + re * c.im);
}


ostream& operator<<(ostream& os, const Complex& c) {
	os << c.re << "," << c.im << "i";
	return os;
}
