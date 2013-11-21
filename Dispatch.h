/*
 * Dispatcher.h
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <vector>
#include <iostream>
#include <math.h>
#include <CannonI.h>
#include <Ice/Ice.h>
#include <IceGrid/IceGrid.h>
#include <IceUtil/IceUtil.h>


class Dispatch{
private:
  int nproc;
  std::vector< ::Cannon::ProcessorPrx> processor;
public:

  Dispatch(int nproc, Ice::ObjectPrx & proxy, CollectorPrx & collector);
  ~Dispatch();
  void distr(const std::vector < ::Cannon::Matrix > & m, const std::vector< ::Cannon::Matrix > &mb);
  int getNproc();
  void  run();
  std::vector< ::Cannon::ProcessorPrx> getProcessor();
  int getLeft(int n);
  int getNorth(int n);
};
#endif

