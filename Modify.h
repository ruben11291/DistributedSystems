
/*
 * Modify.hpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */


#ifndef MODIFY_H
#define MODIFY_H


#include <vector>
#include <CannonI.h>

using namespace Cannon;
using namespace std;

class Modify{
public:
  static vector< ::Cannon::Matrix> split(const ::Cannon::Matrix &m,int);
  static vector< ::Cannon::Matrix> displace_horizontal(const vector< ::Cannon::Matrix> &m,int ord);
  static vector< ::Cannon::Matrix> displace_vertical(const vector< ::Cannon::Matrix> &m,int ord);
  static Cannon::Matrix sum( const Cannon::Matrix & a , const Cannon::Matrix &b);
  static Cannon::Matrix multiply( const Cannon::Matrix & a , const Cannon::Matrix &b);
  
};

#endif
