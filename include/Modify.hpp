
/*
 * Modify.hpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */
#include <Matrix.hpp>
#include <vector>

#ifndef MODIFY_H
#define MODIFY_H



class Modify{
public:
	static vector<Matrix> split(const Matrix &m,int);
	static vector<Matrix> displace_horizontal(const vector<Matrix> &m,int ord);
	static vector<Matrix> displace_vertical(const vector<Matrix> &m,int ord);
};

#endif