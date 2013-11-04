/*
 * Loader.hpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#ifndef LOADER_HPP_
#define LOADER_HPP_

//============================================================================
// Name        : Loader.cpp
// Author      : Ruben Perez Pascual
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <Processor.hpp>
#include <Matrix.hpp>

using namespace std;

 class Loader{

 public:
  Matrix  getA() const;
  Matrix  getB() const;
  void enviar(vector <Processor> p);
  bool can_mult() const;
  Loader(char* A,char* B,char*C,int&);
  Loader();
private:
  Matrix A;
  Matrix B;
  bool can;
  };





#endif /* LOADER_HPP_ */
