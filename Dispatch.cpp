
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

void Dispatch::distr(const std::vector< ::Cannon::Matrix> & mA, const std::vector< ::Cannon::Matrix> &mB, int time){

 
 assert(nproc == mA.size());

 if(time < (int)sqrt(nproc)){
   std::vector< ::Cannon::Matrix> mtA,mtB;
   for( int i= 0; i < nproc; i++){
     Cannon::Matrix tmpA(mA[i]),tmpB(mB[i]);
     processor[i]->injectMatrix(tmpA,tmpB,time);
     mtA.push_back(mA[getLeft(i)]);
     mtB.push_back(mB[getNorth(i)]);
   }
   this->distr(mtA, mtB, time+1);
 }


 // for( int i= 0; i < nproc; i++){
 //    Cannon::Matrix tmpA(mA[i]),tmpB(mB[i]);
 //    processor[i]->injectMatrix(tmpA,tmpB,0);
 //  } 
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
