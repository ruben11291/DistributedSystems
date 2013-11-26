
#include <CannonI.h>
#include <iostream>
#include <cmath>
#include <IceUtil/Monitor.h>
#include <IceUtil/Mutex.h>

void
Cannon::CollectorI::injectSubmatrix(::Ice::Int row,
                                    ::Ice::Int col,
				    ::Ice::Int order,
                                    const ::Cannon::Matrix& m,
                                    const Ice::Current& current)
{
  if(count == 0){
    result = std::vector < ::Cannon::Matrix> (order * order);
  }
  //sigue siendo flag
  cout << "INJECTEDDDD " <<endl;
  Cannon::Matrix tmp(m);
  cout << m.data[0] <<endl;
  result[col + row*order]  = tmp;             ;
  count++;
  if( count == order*order){
    // for(int i =0 ; i < result.size(); i += order){
    //   for(int l=0; l < m.ncols; l++){
    // 	for(int j=i; j < i + order ; j++){
    // 	  for( int k = 0; k < m.ncols; k++){
    // 	    std::cout << result[j].data[k + l*m.ncols] << " ";    
    // 	  }
    // 	  std::cout << " ";
    // 	}
    // 	std::cout << std::endl;
    //   }
    //   std::cout << std::endl;
    // }
    // for(auto i:result){
    //   cout << i.data[0]<<" ";
    // }
    count = 0;
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
Cannon::ProcessorI::injectFirst(const ::Cannon::Matrix& a,
                                ::Ice::Int step,
                                const Ice::Current& current)
{
  
 
  cout << "A FLAG "<<flag << " Step "<<step<<endl;
  if(step == 0 && flag == 0){
    cout << "INITA"<<endl;
    tmp.ncols = a.ncols;
    tmp.data = Cannon::DoubleSeq(a.ncols*a.ncols);
    for(auto i:tmp.data)
      i=0;
  }///////////////////MIRA EL FLAG QUE ESTA MAL
  

  // if(step<order){
  //   flag += 1;
  //   cout<<"A Matrix"<<endl;  
  //   mA = a;
  //   for(auto i:mA.data)
  //     cout << i <<" ";
  //   cout <<endl;
  //   left->begin_injectFirst(mA,step+1);
  //   cout << "LEFT "<<left << endl;
  //   if(flag == 2){
  //     cout << "MULT"<<endl;
  //     Cannon::Matrix t = Modify::multiply(mA,mB);
  //      for(auto i:t.data)
  // 	 cout << i <<" ";
  //      cout <<endl;
  //     Cannon::Matrix aux = Modify::sum(tmp,t);
  //     cout << "TMP "<<endl;
  //     for(auto i:aux.data)
  // 	 cout <<i <<" ";
  //     tmp = aux;
  //     if(step == order-1){
  // 	cout <<"injected Collector"<<endl;
  // 	Ice::AsyncResultPtr r = collector->begin_injectSubmatrix(this->row,this->col,order,tmp);
  // 	r->waitForSent();
  //     }
  //   }
  //   cout <<"assigned A"<<endl;
  //   if(flag == 2) flag = 0;
  // }
  
   
}

void
Cannon::ProcessorI::injectSecond(const ::Cannon::Matrix& b,
                                 ::Ice::Int step,
                                 const Ice::Current& current)
{
 
    cout << "B FLAG "<<flag << " Step "<<step<<endl;

  if(step == 0 && flag == 0){
    cout << "INITB"<<endl;

    tmp.ncols = b.ncols;
    tmp.data = Cannon::DoubleSeq(b.ncols*b.ncols);
    for(auto i:tmp.data)
      i=0;
  }
  if(step<order){
    flag += 1;
    cout<<"B Matrix"<<endl;  
    mB = b;
    for(auto i:mB.data)
      cout << i <<" ";
    cout <<endl;
    cout <<"NORT "<<up << endl;
    up->begin_injectSecond(mB,step+1);
    if(flag == 2){
      cout << "MULT"<<endl;
      Cannon::Matrix t = Modify::multiply(mA,mB);
      for(auto i:t.data)
	cout << i <<" ";
      cout <<endl;
      Cannon::Matrix aux = Modify::sum(tmp,t);
      cout << "TMP "<<endl;
      for(auto i:aux.data)
	cout <<i <<" ";
      
      tmp = aux;
      if(step == order-1){
	cout <<"injected Collector"<<endl;
	Ice::AsyncResultPtr r = collector->begin_injectSubmatrix(this->row,this->col,order,tmp);
	r->waitForSent();
      }
    }
    cout <<"assigned B"<<endl;
    if(flag == 2) flag = 0;
  }
  
  
}

::Cannon::Matrix
Cannon::OperationsI::matrixMultiply(const ::Cannon::Matrix& a,
                                    const ::Cannon::Matrix& b,
                                    const Ice::Current& current)
{
    return ::Cannon::Matrix();
}


