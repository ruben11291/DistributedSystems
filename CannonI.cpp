
#include <CannonI.h>
#include <iostream>


void
Cannon::CollectorI::injectSubmatrix(::Ice::Int row,
                                    ::Ice::Int col,
                                    const ::Cannon::Matrix& m,
                                    const Ice::Current& current)
{
  std::cout << "Fila " << row << " Columna " << col << std::endl;
  for(auto i:m.data)
    std::cout << i <<" ";
  std::cout << std::endl;
  // for(auto i:mA){
  //     for(auto j:i.data){
  // 	cout << j << " ";
  //     }
  //     cout << endl;
  //   }
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
  tmp = Matrix();
  std::cout << "Fila "<<row << " Columna "<<col<<" Order "<<order << std::endl<<"LEFT " <<left << " NORTH " << up << std::endl; 
  
}

void
Cannon::ProcessorI::injectMatrix(const ::Cannon::Matrix& a,
                                 const ::Cannon::Matrix& b,
                                 ::Ice::Int step,
                                 const Ice::Current& current)
{
  // if(step == 0){
  //   tmp.ncols = a.ncols;
  //   tmp.data = std::vector<double>(tmp.ncols);
  //   for(auto i:tmp.data)
  //     i = 0;
  // }
  // if(step < order){
  //   tmp = ::Modify::sum(tmp , ::Modify::multiply(a,b));
    
  //   if(step < order-1)this->collector->injectSubmatrix(this->row,this->col,tmp);//send to collector
  // }
}



