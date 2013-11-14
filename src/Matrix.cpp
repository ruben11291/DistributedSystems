
/*
 * Matrix.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#include <Matrix.hpp>
#include <vector>

using namespace std;
Matrix::Matrix(int ncol):ncol(ncol){
	uuid = boost::uuids::random_generator()();

	data = vector<double>(ncol*ncol);

}

Matrix::Matrix():ncol(0){
	uuid = boost::uuids::random_generator()();

}

Matrix::Matrix(const Matrix &_m):ncol(_m.ncol){
	uuid = _m.uuid;

	 data = vector<double>(ncol*ncol);
	for(int i = 0;i<data.size();i++)
			data[i] = _m.data[i];
	
}
Matrix 
Matrix::multiply(const Matrix & _mat){
	Matrix temp(_mat.ncol);
	double sum = 0;
	for(int i = 0;i< ncol; i++){
		for(int j = 0; j <_mat.ncol ; j++){
			for ( int k = 0; k< ncol ;k++){
				sum += data[i*_mat.ncol + k]*_mat.data[k*_mat.ncol + j];
			}
			temp.data[i*_mat.ncol + j] = sum;
			sum = 0;
		}
	}
	return temp;
}

Matrix::~Matrix(){
	
}

string
Matrix::toString() const{
	stringstream b;
	for(int i=0;i<ncol*ncol;i++){
		if(i%ncol==0) b<<endl;
			b<<data[i] <<" ";
			
	}
	
	return b.str();
}		

Matrix &
Matrix::operator = (const Matrix & _m){
	if(this == &_m) return *this;
	
	ncol=_m.ncol;
	
	data = vector<double>(ncol*ncol);

	for(int i = 0;i<data.size();i++){
			data[i] = _m.data[i];
	}

	return *this;
}

Matrix Matrix::operator + (const Matrix & _m){
	Matrix tmp(_m.ncol);
	for(int i = 0; i < _m.ncol*_m.ncol; i++)
		tmp.data[i] = data[i]+_m.data[i];
	return tmp;
}