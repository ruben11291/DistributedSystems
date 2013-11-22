#ifndef __CannonI_h__
#define __CannonI_h__

#include <Cannon.h>
#include <Modify.h>

namespace Cannon
{

class CollectorI : virtual public Collector
{
public:
  std::vector < ::Cannon::Matrix > result;
  int count = 0;
  virtual void injectSubmatrix(::Ice::Int,
                                 ::Ice::Int,
			       ::Ice::Int,
                                 const ::Cannon::Matrix&,
                                 const Ice::Current&);
};

class ProcessorI : virtual public Processor
{
public:

  ::Cannon::Matrix tmp;
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

    virtual void injectMatrix(const ::Cannon::Matrix&,
                              const ::Cannon::Matrix&,
                              ::Ice::Int,
                              const Ice::Current&);

    
};


}
#endif
