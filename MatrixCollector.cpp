
#include <CannonI.h>
#include <Ice/Ice.h> 

using namespace Ice;

class CollectorMatrix : public Ice::Application{
  int run(int argc, char** argv){
    Cannon::CollectorPtr collector = new Cannon::CollectorI();
    
    Ice::ObjectAdapterPtr CollAdapter = communicator()->createObjectAdapterWithEndpoints("CollectorAdapter",":tcp -h localhost -p 10000");
    CollAdapter->add(collector,communicator()->stringToIdentity("Collector"));
     
    CollAdapter->activate();
    shutdownOnInterrupt();
    communicator()->waitForShutdown();
  }
};

int main(int argc,char **argv){
  CollectorMatrix app;
  return app.main(argc,argv);
}
