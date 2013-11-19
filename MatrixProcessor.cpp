
#include <CannonI.h>
#include <Ice/Ice.h>

using namespace Ice;
using namespace std;

class ProcessorMatrix: public Application{
  int run(int argc , char**argv){
    Cannon::ProcessorPtr proc = new Cannon::ProcessorI();
    
    Ice::ObjectAdapterPtr adapter = communicator()-> createObjectAdapter("ProcessorAdapter");
    Ice::ObjectPrx proxy = adapter->add(proc, communicator()->stringToIdentity("Procesador1"));
    
    cout << communicator()->proxyToString(proxy) <<endl;

    adapter->activate();
    shutdownOnInterrupt();
    communicator()->waitForShutdown();

  }

};

  int main(int argc,char**argv){
    ProcessorMatrix app;
    return app.main(argc,argv);
  }
