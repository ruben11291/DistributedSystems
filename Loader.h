/*
 * Loader.hpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <CannonI.h>
#include <cmath>

#ifndef LOADER_HPP_
#define LOADER_HPP_


using namespace Cannon;
using namespace std;

 class Loader{

 public:
   Cannon::Matrix  getA() const;
   Cannon::Matrix  getB() const;
  Loader(char* A,char* B,char*C,int&);
  Loader();
private:
   Cannon::Matrix A;
   Cannon::Matrix B;
  };





#endif /* LOADER_HPP_ */
