#ifndef __CannonI_h__
#define __CannonI_h__

#include <Cannon.h>
#include <Modify.h>
#include <IceUtil/Mutex.h>

namespace Cannon
{

class CollectorI : virtual public Collector
{
public:
  std::vector < ::Cannon::Matrix > result;
  int count = 0;
  bool inicio = true;
  virtual void injectSubmatrix(::Ice::Int,
                                 ::Ice::Int,
			       ::Ice::Int,
                                 const ::Cannon::Matrix&,
                                 const Ice::Current&);
};

class ProcessorI : virtual public Processor
{
public:
  int countA=0,countB=0;
  bool pasado = false;
  ::Cannon::Matrix tmp;
  ::std::vector < ::Cannon::Matrix > bufferA, bufferB;
  ::Cannon::ProcessorPrx left,up;
  ::Ice::Int row,col,order;
  ::Cannon::CollectorPrx collector;

  virtual void init(::Ice::Int,
                      ::Ice::Int,
                      const ::Cannon::ProcessorPrx&,
                      const ::Cannon::ProcessorPrx&,
                      ::Ice::Int,
                      const ::Cannon::CollectorPrx&,
                      const Ice::Current&);

   
    virtual void injectFirst(const ::Cannon::Matrix&,
                             ::Ice::Int,
                             const Ice::Current&);

    virtual void injectSecond(const ::Cannon::Matrix&,
                              ::Ice::Int,
                              const Ice::Current&);

    
};

class OperationsI : virtual public Operations
{
public:

    virtual ::Cannon::Matrix matrixMultiply(const ::Cannon::Matrix&,
                                            const ::Cannon::Matrix&,
                                            const Ice::Current&);
};

}
#endif
