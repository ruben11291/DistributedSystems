
#include <CannonI.h>
#include <Ice/Ice.h>
#include <string>
#include <sstream>


using namespace Ice;
using namespace std;

class ProcessorMatrix: public Application{
  int run(int argc , char**argv){
    string str;
    str = string("Processor") + argv[1];
    ProcessorPtr proc = new Cannon::ProcessorI();
    
    Ice::ObjectAdapterPtr adapter = communicator()-> createObjectAdapter("ProcessorAdapter");
    Ice::ObjectPrx proxy = adapter->add(proc, communicator()->stringToIdentity(str.c_str()));
    

    adapter->activate();
    shutdownOnInterrupt();
    communicator()->waitForShutdown();

  }

};

  int main(int argc,char**argv){
    ProcessorMatrix app;
    return app.main(argc,argv);
  }
