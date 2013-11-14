
/*
 * Matrix.hpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#include <string>
#include <iostream>
 #include <vector>
#include <sstream>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp> 

#ifndef MATRIX_H
#define MATRIX_H



using namespace std;

class Matrix{
	public:
		vector <double> data;
		int ncol;
		boost::uuids::uuid uuid;
		Matrix(int ncol);
		Matrix();
		Matrix(const Matrix &);
		~Matrix();
		Matrix multiply(const Matrix &);
		string toString() const;
		Matrix& operator = (const Matrix & );
		Matrix operator + (const Matrix & _m);

};

#endif