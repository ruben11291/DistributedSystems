
/*
 * Loader.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#include <Loader.hpp>

using namespace std;

Loader::Loader(){

}

Loader::Loader(char * fileA, char * fileB,char* fileC,int& np){
  ifstream fA(fileA),fB(fileB),fC(fileC);
  if(!fA.is_open()) throw -1;
  if(!fB.is_open()) throw -2;
  if(!fC.is_open()) throw -3;
  int filA,filB;
  fA>>filA;
  fB>>filB;
  fC>>np;
  cout << sqrt(np)<< " ";
  cout <<double( (int)sqrt(np))<<" ";
  assert(filA == filB);
  assert(sqrt(np) == double( (int)sqrt(np)));
  assert(np > 1 and (int)sqrt(np) > 1);
  assert((int)filA % (int)sqrt(np) == 0  );// if order of data is div. by the order of array of processors.

  A = Matrix(filA);
  B = Matrix(filB);

  for(int i=0;i<A.ncol*A.ncol;i++){
      fA>>A.data[i];
  }
  
  for(int i=0;i<B.ncol*B.ncol;i++){
      fB>>B.data[i];
  }

  fA.close();
  fB.close();
}

Matrix 
Loader::getA() const{
return this->A;
}

Matrix 
Loader::getB() const {
  return this->B;
}

