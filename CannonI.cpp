
#include <CannonI.h>
#include <iostream>
#include <cmath>

void
Cannon::CollectorI::injectSubmatrix(::Ice::Int row,
                                    ::Ice::Int col,
				    ::Ice::Int order,
                                    const ::Cannon::Matrix& m,
                                    const Ice::Current& current)
{
  if(count == 0 ){
    result = std::vector < ::Cannon::Matrix> (order * order);
  }
  
  result[col + row*order] = m;
  count++;
  if( count == result.size()){
    for(int i =0 ; i < result.size(); i += order){
      for(int l=0; l < m.ncols; l++){
  	for(int j=i; j < i + order ; j++){
  	  for( int k = 0; k < m.ncols; k++){
  	    std::cout << result[j].data[k + l*m.ncols] << " ";    
	  }
	  std::cout << " ";
	}
	std::cout << std::endl;
      }
      std::cout << std::endl;
    }
  }
}

void
Cannon::ProcessorI::init(::Ice::Int row,
                         ::Ice::Int col,
                         const ::Cannon::ProcessorPrx& up,
                         const ::Cannon::ProcessorPrx& left,
                         ::Ice::Int order,
                         const ::Cannon::CollectorPrx& target,
                         const Ice::Current& current)
{
  this->row = row;
  this->col = col;
  this->order = order;
  this->left = left;
  this->up = up;
  this->collector = target;
  
}

void
Cannon::ProcessorI::injectMatrix(const ::Cannon::Matrix& a,
                                 const ::Cannon::Matrix& b,
                                 ::Ice::Int step,
                                 const Ice::Current& current)
{
  
  if(!step){
    tmp.ncols = a.ncols;
    tmp.data = Cannon::DoubleSeq(tmp.ncols * tmp.ncols);
    for(auto i:tmp.data)
      i = 0;
  }
  if(step < order){
 
    Cannon::Matrix mult = ::Modify::multiply(a,b);
    tmp = ::Modify::sum(tmp , mult); 
    
  if(step == order-1) collector->injectSubmatrix(this->row,this->col, order, tmp);//send to collector
  
  }
 
  
}



