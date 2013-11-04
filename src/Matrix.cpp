
#include <Matrix.hpp>
#include <string>
#include <iostream>

using namespace std;
Matrix::Matrix(int _fil, int _col):fil(_fil),col(_col){
	data = new double*[fil];

	for(int i = 0;i<fil;i++)
		data[i] =  new double[col];
}

Matrix::Matrix():fil(0),col(0),data(0){

}

Matrix::Matrix(const Matrix &_m):fil(_m.fil),col(_m.col),data(0){
	 data = new double*[fil];
	for(int i = 0;i<fil;i++){
		data[i] =  new double[col];
		for(int j=0;j<col;j++)
			data[i][j] = _m.data[i][j];
	}
}
Matrix 
Matrix::multiply(const Matrix & _mat){
	Matrix temp(fil,_mat.col);
	double sum = 0;
	for(int i = 0;i< fil; i++){
		for(int j = 0; j <_mat.col ; j++){
			for ( int k = 0; k< col ;k++){
				sum += data[i][k]*_mat.data[k][j];
			}
			temp.data[i][j] = sum;
			sum = 0;
		}
	}
	return temp;
}

Matrix::~Matrix(){
	for(int i = 0;i<fil;i++)
		delete [] data[i];
	delete [] data;
}

string
Matrix::toString() const{
	stringstream b;
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			b<<data[i][j] <<" ";
		}
		b <<"\n";
	}
	return b.str();
}		

Matrix &
Matrix::operator = (const Matrix & _m){
	if(this == &_m) return *this;
	for (int i = 0;i<fil;i++)
		delete []data[i];
	delete [] data;
	

	fil=_m.fil;
	col=_m.col;
	
	data = new double*[fil];

	for(int i = 0;i<fil;i++){
		data[i] =  new double[col];
		for(int j=0;j<col;j++)
			data[i][j] = _m.data[i][j];
	}

	return *this;
}

