
#include <iostream>
#include <fstream>
#include <Loader.hpp>
#include <vector>

using namespace std;

Loader::Loader(){

}

Loader::Loader(char * fileA, char * fileB,char* fileC,int& np):can(true){
  ifstream fA(fileA),fB(fileB),fC(fileC);
  if(!fA.is_open()) throw -1;
  if(!fB.is_open()) throw -2;
  if(!fC.is_open()) throw -3;
  int filA,colA,filB,colB;
  fA>>filA;
  fA>>colA;
  fB>>filB;
  fB>>colB;
  fC>>np;
  if(colA != filB) //don`t multiply arrays
    can = false;
  
  A = Matrix(filA,colA);
  B = Matrix(filB,colB);

  for(int i=0;i<A.fil;i++){
    for(int j=0;j<A.col;j++){
      fA>>A.data[i][j];
    }
  }
  
  for(int i=0;i<B.fil;i++){
    for(int j=0;j<B.col;j++){
      fB>>B.data[i][j];
    }
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
bool 
Loader::can_mult() const{
  return this->can;
}
void
Loader::enviar(vector <Processor> p){
  for(vector<Processor>::iterator it = p.begin();it!=p.end(); it++)
;
}

