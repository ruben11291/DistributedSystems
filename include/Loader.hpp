/*
 * Loader.hpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <Processor.hpp>
#include <Matrix.hpp>
#include <cassert>
#ifndef LOADER_HPP_
#define LOADER_HPP_



using namespace std;

 class Loader{

 public:
  Matrix  getA() const;
  Matrix  getB() const;
  Loader(char* A,char* B,char*C,int&);
  Loader();
private:
  Matrix A;
  Matrix B;
  };





#endif /* LOADER_HPP_ */
