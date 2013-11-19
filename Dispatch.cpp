
#include <Dispatch.h>
#include <IceGrid/IceGrid.h>
#include <iostream>
#include <cassert>


Dispatch::Dispatch(int npro, Ice::ObjectPrx& proxy):nproc(npro){
  // processor = std::vector< Cannon::ProcessorPrx > (nproc);
  processor = std::vector < Cannon::ProcessorPrx > ();
  IceGrid::QueryPrx query = IceGrid::QueryPrx::checkedCast(proxy);
   Ice::ObjectProxySeq seq;

  //  string type = Cannon::Procesor::ice_staticId();
  seq = query->findAllObjectsByType("::Cannon::Processor");
 
 Cannon::ProcessorPrx pr;
 std::cout << "elemento"<<std::endl;
  for(auto i:seq){
    pr = Cannon::ProcessorPrx::checkedCast(i);
    processor.push_back(pr);
    std::cout << "elemento"<<std::endl;
  }
  //assert(npro == processor.size());
  
   // // for(int i=0;i<nproc;i++)
   // //  processor[i] = Processor(i,nproc);
  
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
  // for(int i = 0; i<mA.size();i++){
  //   processor[i]->init((int)(i / (int)sqrt(nproc)), i % (int)sqrt(nproc), processor[] , processor[] , (int)sqrt(nproc) , 
  // }
  // for( int i= 0; i < nproc; i++){
  //   processor[i].setA(mA[i]);
  //   processor[i].setB(mB[i]);
  // }


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
