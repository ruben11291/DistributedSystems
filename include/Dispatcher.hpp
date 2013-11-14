/*
 * Dispatcher.hpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#include <Matrix.hpp>
#include <vector>
#include <iostream>
#include <math.h>
#include <Processor.hpp>
#ifndef DISPATCHER_H
#define DISPATCHER_H

class Dispatcher{
private:
	int nproc;
	vector<Processor> processor;
public:

	Dispatcher(int nproc);
	~Dispatcher();
	void distr(const vector<Matrix> & m, const std::vector<Matrix> &mb);
	int getNproc();
	std::vector<Matrix> getResult();
	void  run();
	vector<Processor> getProcessor();
};
#endif
