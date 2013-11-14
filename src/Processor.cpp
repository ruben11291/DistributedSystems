/*
 * Processor.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

/*TODO*/


#include <Processor.hpp>

Processor::Processor(int _id,int t):id(_id),totalproc(t){
	tmp= Matrix((int)sqrt(t));
}
Processor::Processor(){

}

Processor::~Processor(){

}

int Processor::getId(){
	return id;
}


void Processor::setA(Matrix _A){
	A = _A;
}
void Processor::setB(Matrix _B){
	B = _B;
}

Matrix Processor::getA(){ return A;}
Matrix Processor::getB(){ return B;}
Matrix Processor::getResult(){ return tmp;}

void Processor::run(){
	// cout << A.data[0] << " " <<B.data[0]<<endl;
	tmp = tmp + A.multiply(B);
	// cout << tmp.data[0]<<endl;
}

int Processor::getLeft(){
	if(id % (int)sqrt(totalproc) == 0)
		return (id + ((int)sqrt(totalproc) - 1) );
	else return (id - 1);
}

int Processor::getNorth(){
	if(id < (int)sqrt(totalproc) )
		return (totalproc + (id- (int)sqrt(totalproc)));
	else return (id-((int)sqrt(totalproc)) % totalproc ); 
}
