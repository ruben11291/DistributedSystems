/*
 * Processor.hpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#include <math.h>
#include <Matrix.hpp>

#ifndef PROCESSOR_HPP_
#define PROCESSOR_HPP_

class Processor{
  public:
  	Processor(int id,int t);
  	Processor();
  	~Processor();
    void setA(Matrix A);
    void setB(Matrix B);
    Matrix getResult();
    Matrix getA();
    Matrix getB();
    void run();

  	int getId();
  	int getLeft();
  	int getNorth();
  private:
  	int id;
  	int totalproc;
    Matrix A;
    Matrix B;
    Matrix tmp;

};



#endif /* PROCESSOR_HPP_ */
