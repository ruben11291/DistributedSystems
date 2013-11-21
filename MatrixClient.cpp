//============================================================================
// Name        : Main.cpp
// Author      : Ruben Perez Pascual
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <Loader.h>
#include <Modify.h>
#include <Dispatch.h>
#include <Ice/Ice.h>
#include <IceGrid/IceGrid.h>
#include <IceUtil/IceUtil.h>

using namespace Ice;
using namespace std;
using namespace Cannon;




class MatrixClient: public Ice::Application{
  int run(int argc, char**argv){
    Loader loader;
    int ord,nproc;
    
    
    try{
      loader= Loader(argv[1],argv[2],argv[3],nproc);
    }catch(int e){
      cout<<"Error cargando el fichero de argumento";
      switch(e){
      case -1: cout<<" 1"<<endl;break;
      case -2: cout<<" 2"<<endl;break;
      case -3: cout<<" 3"<<endl;break;
	
	
      }
      return -1;
    }
    ord = (int)sqrt(nproc);//dimension matrix

    //Create query for get processors' proxies
    // try{
     Ice::ObjectPrx proxy = communicator()->stringToProxy("IceGrid/Query");
     Ice::ObjectPrx col = communicator()->stringToProxy("Collector");
     CollectorPrx collector = CollectorPrx::checkedCast(col);
     // }catch(){
    // }
    
    
  
    Cannon::Matrix A (loader.getA());
    Cannon::Matrix B (loader.getB());
    
    
    // cout << "MATRIX A"<<endl<<A.toString()<<endl;
    // cout << "MATRIX B"<<endl<<B.toString()<<endl;
    
    Cannon::Matrix R=  Modify::multiply(A,B);
    // cout << "RESULT MATRIZ"<<endl<<R.toString()<<endl;
    // Cannon::Matrix pruba =A;
    vector < Cannon::Matrix> vA = Modify::split(A,ord);
    std::vector< Cannon::Matrix> vB = Modify::split(B,ord);
    
    
    vA = Modify::displace_horizontal(vA,ord);
    vB = Modify::displace_vertical(vB,ord);
    
   
     Dispatch dispatcher(nproc, proxy,collector);//create dispatcher for proccesors
    dispatcher.distr(vA,vB);
    dispatcher.run();
   
    
    return 0;
  }
};

int main(int argc,char**argv) {
  if(argc < 4){
    cout << "Error."<<endl<<" Use ./bin/multcannon <file_m1> <file_m2> <file_nproc>"<<endl;
    return -1;
  }

  MatrixClient app;
  return app.main(argc,argv);
}
