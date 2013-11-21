
#include <Dispatch.h>
#include <IceGrid/IceGrid.h>
#include <iostream>
#include <cassert>


Dispatch::Dispatch(int npro, Ice::ObjectPrx& proxy, CollectorPrx& collector):nproc(npro){
  
  processor = std::vector < Cannon::ProcessorPrx > ();
  
  IceGrid::QueryPrx query = IceGrid::QueryPrx::checkedCast(proxy);
   Ice::ObjectProxySeq seq;

  seq = query->findAllObjectsByType("::Cannon::Processor");
 
 Cannon::ProcessorPrx pr;
 int size = seq.size();
 for(auto i:seq){
   std::cout << i <<std::endl;
   pr = Cannon::ProcessorPrx::checkedCast(i);
   processor.push_back(pr);
 }
 
 for(int i =0; i<size; i++){
   processor[i]->init( (int)(i/(int)sqrt(nproc)) , (int)(i%(int)sqrt(nproc)) , processor[getLeft(i)],processor[getNorth(i)],(int)sqrt(nproc), collector);
 }

}
 
Dispatch::~Dispatch(){
  
}

void Dispatch::distr(const std::vector< ::Cannon::Matrix> & mA, const std::vector< ::Cannon::Matrix> &mB){
  // for(auto i:mA)
  // 	cout << i.toString()<<endl;
  // cout.flush();
  // for(auto i:mB)
  // 	cout<<i.toString()<<endl;
  // cout.flush();
  
  Matrix A;
  A.ncols = 5;
  A.data = Cannon::DoubleSeq();
 assert(nproc == mA.size());
  for( int i= 0; i < nproc; i++){
    Cannon::Matrix tmpA(mA[i]),tmpB(mB[i]);
    processor[i]->injectMatrix(tmpA,tmpB,0);
  }


  // for(int i = 0; i<nproc;i++){
  // 	cout<<" I "<<i<<" Processor "<<processor[i].getId()<< endl;
  // 	for(int j =0;j<processor[i].getA().data.size();j++)
  // 		cout<<processor[i].getA().data[j]<<" ";
  // 	cout<<endl;
  // 	for(int j =0;j<processor[i].getB().data.size();j++)
  // 		cout<<processor[i].getB().data[j]<<" ";
  // 	cout<<endl;
  // }
  
  
}

void Dispatch::run(){
  // std::vector< ::Cannon::Matrix> auxA,auxB;
  
  // int l = (int)sqrt(nproc);
  // for(int i = 0; i < l-1; i++){
  //   auxA = std::vector<Matrix>();
  //   auxB = std::vector<Matrix>();
  //   for( int j = 0; j < nproc; j++){
  //     processor[j].run();
  //     auxA.push_back(processor[j].getA());
  //     auxB.push_back(processor[j].getB());
  //   }
  // 	  for( int j = 0; j < nproc; j++){
  // 	    processor[processor[j].getLeft()].setA(auxA[j]);
  // 	    processor[processor[j].getNorth()].setB(auxB[j]);
  // 	  }
	  
  // }
  // for( int j = 0; j < nproc; j++)
  //   processor[j].run();
}

	

int Dispatch::getNproc(){
   return nproc;
}

std::vector< ::Cannon::ProcessorPrx> Dispatch::getProcessor(){
	 return processor;
}

int Dispatch::getLeft(int id){
	if(id % (int)sqrt(nproc) == 0)
		return (id + ((int)sqrt(nproc) - 1) );
	else return (id - 1);
}
int Dispatch::getNorth(int id){
	if(id < (int)sqrt(nproc) )
		return (nproc + (id- (int)sqrt(nproc)));
	else return (id-((int)sqrt(nproc)) % nproc ); 
}
