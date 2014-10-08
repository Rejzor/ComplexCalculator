
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Complex.hpp"
#include "Matrix.hpp"


/*
Damian Kuter 209456 Poniedziałek 11.15

Implementacja dodatkowych metod w klasie „Matrix”:
9. Matrix transpose(void); - Transpozycja macierzy

Wprowadzenie obslugi wyjatkow (m.in. komendy „throw”, „try”, „catch”). Np. w przypadku
gdy dodajemy macierze o roznych wymiarach uzytkownik jest informowany o problemie ale
program nie konczy dzialania. Wyjatki powinny sie pojawiac przy wystepowaniu roznych
bledow, nie tylko tego wymienionego powyzej.
*/

int main(int argc, char** argv)
{
	Complex c1(1.0, 2.0), c2(6.0, 4.0);
	cout << "Test zespolonych:" << endl << endl;
	cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
	cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
	cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;
	cout << endl << endl;

	Matrix m1(c1, 3, 3), m2(c2, 3, 3);
	//zamiast c1 i c2 mozna wstawic inne obiekty np Complex(13.0, 37.0)
	cout << "Test macierzy:" << endl << endl;
	cout << m1 << " + \n" << m2 << " = \n" << m1 + m2 << endl << endl;
	cout << m1 << " - \n" << m2 << " = \n" << m1 - m2 << endl << endl;
	cout << m1 << " * \n" << m2 << " = \n" << m1 * m2 << endl << endl;
	cout << endl;

	cout << "Transpozycja:" << endl << endl;
	m2.data[0][0] = Complex(1.0,1.0);
	m2.data[0][1] = Complex(1.0,1.0);
	m2.data[0][2] = Complex(1.0,1.0);
	m2.data[1][0] = Complex(2.0,2.0);
	m2.data[1][1] = Complex(2.0,2.0);
	m2.data[1][2] = Complex(2.0,2.0);
    m2.data[2][0] = Complex(4.0,4.0);
	m2.data[2][1] = Complex(4.0,4.0);
	m2.data[2][2] = Complex(4.0,4.0);
	cout << m2.transpose() << endl << endl;

	try {
		Matrix e1(Complex(0.0, 0.0), -2, 3);
	}
	catch (string s)
	{
		cout << s << endl;
	}

	try {
		Matrix e2(Complex(0.0, 0.0), 2, 2), e3(Complex(1.1, 2.2), 3, 3);
		cout << e2 * e3;
	}
	catch (string s)
	{
		cout << s << endl;
	}


	cin.get();
	return 0;
}
