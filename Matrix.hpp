
#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <vector>
#include <iostream>

#include "Complex.hpp"

using namespace std;

class Matrix
{
public:
	vector< vector<Complex> > data;
	int rows, columns;

	Matrix(const Complex &c, int row, int col);

	Matrix transpose();

	Matrix operator+(const Matrix &m);
	Matrix operator-(const Matrix &m);
	Matrix operator*(const Matrix &m);

	friend ostream & operator<<(ostream &os, const Matrix &m);
};

#endif
