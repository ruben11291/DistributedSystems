
/*
 * Loader.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#include <Loader.h>
#include <Cannon.h>
#include <CannonI.h>

using namespace Cannon;
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
  assert(filA == filB);
  assert(sqrt(np) == double( (int)sqrt(np)));
  assert(np > 1 and (int)sqrt(np) > 1);
  assert((int)filA % (int)sqrt(np) == 0  );// if order of data is div. by the order of array of processors.

  A = Cannon::Matrix();
  B = Cannon::Matrix();
  A.ncols = filA;
  B.ncols = filB;
  A.data = Cannon::DoubleSeq( filA * filA );
  B.data = Cannon::DoubleSeq( filB * filB );
  for(int i=0;i<A.ncols*A.ncols;i++){
    fA>> A.data[i];
  }
  
  for(int i=0;i<B.ncols*B.ncols;i++){
      fB>>B.data[i];
  }

  fA.close();
  fB.close();
}

Cannon::Matrix 
Loader::getA() const{
return this->A;
}

Cannon::Matrix 
Loader::getB() const {
  return this->B;
}

