#include <string>
#include "Matrix.hpp"

Matrix::Matrix(const Complex& c, int rows, int columns)
{
	if (rows <= 0 || columns <= 0) throw string("wymiary macierzy musza byc dodatnie");

	this->rows = rows;
	this->columns = columns;

	data.resize(rows);

	for (int row = 0; row < rows; ++row)
	{
		data[row].resize(columns);

		for (int column = 0; column < columns; ++column)
			data[row][column] = c;
	}
}

Matrix Matrix::operator+(const Matrix& m)
{
	if (m.rows != rows || m.columns != columns) throw string("wymiary macierzy nie zgadzaja sie");

	Matrix result(Complex(0.0, 0.0), rows, columns);

	for (int row = 0; row < rows; ++row)
		for (int column = 0; column < columns; ++column)
			result.data[row][column] = data[row][column] + m.data[row][column];

	return result;
}

Matrix Matrix::operator-(const Matrix& m)
{
	if (m.rows != rows || m.columns != columns) throw string("wymiary macierzy nie zgadzaja sie");

	Matrix result(Complex(0.0, 0.0), rows, columns);

	for (int row = 0; row < rows; ++row)
		for (int column = 0; column < columns; ++column)
			result.data[row][column] = data[row][column] - m.data[row][column];

	return result;
}

Matrix Matrix::operator*(const Matrix& m)
{
	if (m.rows != rows || m.columns != columns) throw string("wymiary macierzy nie zgadzaja sie");

	Matrix result(Complex(0.0, 0.0), rows, columns);

	for (int row = 0; row < rows; ++row)
		for (int column = 0; column < columns; ++column)
			result.data[row][column] = data[row][column] * m.data[row][column];

	return result;
}

Matrix Matrix::transpose()
{
	Matrix result(Complex(0.0, 0.0), columns, rows);

	for (int row = 0; row < rows; ++row)
		for (int column = 0; column < columns; ++column)
			result.data[row][column] = data[column][row];

	return result;
}


ostream& operator<<(ostream& os, const Matrix &m) {
	for (int i = 0;i<m.data.size(); i++) {
		for (int j = 0;j<m.data.at(0).size(); j++)
			os << m.data.at(i).at(j) << " ";
		os << endl;
	}
	return os;
}

