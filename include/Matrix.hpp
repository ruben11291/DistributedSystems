
#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <sstream>

using namespace std;

class Matrix{
	public:
		double **data;
		int fil;
		int col;
		Matrix(int fil,int col);
		Matrix();
		Matrix(const Matrix &);
		~Matrix();
		Matrix multiply(const Matrix &);
		string toString() const;
		Matrix& operator = (const Matrix & );
		// Matrix operator=(const Matrix &_m);
};

#endif