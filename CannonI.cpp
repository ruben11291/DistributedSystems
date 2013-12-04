
#include <CannonI.h>
#include <iostream>
#include <fstream>
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
    result = std::vector < ::Cannon::Matrix>( order * order);
  }
  cout << "Matrix injected" <<endl;
  result[col + row*order ] = m;
  count += 1;
  if( count == order*order){
    ofstream out("../../../../cannon_result.m");
    cout<<" RESULT "<<endl;
    for(int i =0 ; i < result.size(); i += order){
      for(int l=0; l < m.ncols; l++){
    	for(int j=i; j < i + order ; j++){
    	  for( int k = 0; k < m.ncols; k++){
    	    out << result[j].data[k + l*m.ncols] << " ";
    	  }
    	  out << " ";
    	}
    	out << std::endl;
      }
      out << std::endl;
    }
    count = 0;
    out.close();
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
  countA = countB = 0;
  bufferA =  std::vector < ::Cannon::Matrix> (order);
  bufferB = std::vector <  ::Cannon::Matrix> (order); 
}

void
Cannon::ProcessorI::injectFirst(const ::Cannon::Matrix& a,
                                ::Ice::Int step,
                                const Ice::Current& current)
{
  
  
  if(step<order){
    countA +=1;
    bufferA[step] = a;   

    try{
      Ice::AsyncResultPtr r = left->begin_injectFirst(a,step+1);
    }catch(int e){
      cout << "EXCEPTION "<<endl;
    }

    if(countA == order and countB == order){
      tmp.ncols = a.ncols;
      tmp.data = Cannon::DoubleSeq(tmp.ncols*tmp.ncols);
      for(auto& i:tmp.data)
	i = 0.0;

      for(int i = 0; i < order; i++){
	Cannon::Matrix t = Modify::multiply(bufferA[i],bufferB[i]);
	Cannon::Matrix aux = Modify::sum(tmp,t);
	tmp = aux;	
      }
     
      cout <<"injected to Collector"<<endl;
      collector->injectSubmatrix(this->row,this->col,order,tmp);
     
    }
  }

}

void
Cannon::ProcessorI::injectSecond(const ::Cannon::Matrix& b,
                                 ::Ice::Int step,
                                 const Ice::Current& current)
{
  
  if( step < order){
    countB +=1;
    bufferB[step] = b;

    try{
      Ice::AsyncResultPtr r = up->begin_injectSecond(b,step+1);
    }catch(int e){
      cout<<"EXCEPTION "<<endl;
    }

    if(countA == order and countB == order){
      tmp.ncols = b.ncols;
      tmp.data = Cannon::DoubleSeq(tmp.ncols*tmp.ncols);
      for(auto& i:tmp.data)
	i = 0.0;
      for(int i = 0; i < order; i++){
	Cannon::Matrix t = Modify::multiply(bufferA[i],bufferB[i]);
	Cannon::Matrix aux = Modify::sum(tmp,t);
	tmp = aux;	
      }
      
      cout <<"injected to Collector"<<endl;
      collector->injectSubmatrix(this->row,this->col,order,tmp); 
    }
  }
}

::Cannon::Matrix
Cannon::OperationsI::matrixMultiply(const ::Cannon::Matrix& a,
                                    const ::Cannon::Matrix& b,
                                    const Ice::Current& current)
{
    return ::Cannon::Matrix();
}


