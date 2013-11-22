/*
 * Modify.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#include <Modify.h>
#include <Cannon.h>
#include <CannonI.h>

using namespace Cannon;

std::vector<Matrix> Modify::split(const Matrix &m,int ord){
  std::vector<Cannon::Matrix> v;
  
  for(int a = 0; a< m.ncols*m.ncols; a+=m.ncols*(m.ncols/ord)){
    for(int i = a; i< m.ncols+a; i+=m.ncols/ord){
      Cannon::Matrix aux = Cannon::Matrix();
      aux.ncols = m.ncols/ord;
      for( int j= 0; j< m.ncols/ord; j++){
	for(int k = i ; k< m.ncols/ord+i; k++)
	  aux.data.push_back(m.data[j*m.ncols + k] );
      }
      v.push_back(aux);
    }
  }
  
  return v;
}

std::vector<Matrix> Modify::displace_horizontal(const vector<Matrix> &m,int ord){
  std::vector<Matrix> v;
  int count = 0;
  for(int i = 0;i < m.size(); i+=ord){
    for(int j = i+count; j < i+ord; j++)
      v.push_back(m[j]);
    for(int j = i; j< i+count ; j++)
      v.push_back(m[j]);
    count++;
  }
  return v;
}
std::vector<Matrix>  Modify::displace_vertical(const std::vector<Matrix>& m,int ord){
  std::vector<Matrix> v,aux;
  
  for(int i = 0;i<ord;i++){
    for(int j = i; j<ord ; j++)
      v.push_back(m [ i + j * ord ] );
    for(int j = 0; j<i ; j++)
      v.push_back(m [ i + j * ord ] );
  }
  
	for(int i = 0; i < ord; i++)
	  for( int j = 0; j < ord; j++)
	    aux.push_back(v[ j * ord + i ]);
	
	return aux;
}


Cannon::Matrix Modify::multiply(const Cannon::Matrix& _m, const Cannon::Matrix&  _mat){
  ::Cannon::Matrix temp;
  temp.ncols = _m.ncols;
  temp.data = Cannon::DoubleSeq (temp.ncols*temp.ncols);
  double sum = 0;
  for(int i = 0;i< _mat.ncols; i++){
    for(int j = 0; j <_m.ncols ; j++){
      for ( int k = 0; k< _m.ncols ;k++){
	sum += _m.data[i*_mat.ncols + k]*_mat.data[k*_mat.ncols + j];
      }
      temp.data[i*_mat.ncols + j] = sum;
      sum = 0;
    }
  }
  return temp;
}




Cannon::Matrix  Modify::sum(const ::Cannon::Matrix& a, const ::Cannon::Matrix& b){
  ::Cannon::Matrix tmp;
  
  tmp.ncols = a.ncols;
  tmp.data = Cannon::DoubleSeq( tmp.ncols*tmp.ncols );
  for(int i = 0; i < a.ncols*a.ncols; i++)
    tmp.data[i] = a.data[i]+b.data[i];
  
  return tmp;
}
