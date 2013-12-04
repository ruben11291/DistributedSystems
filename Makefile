CXXFLAGS=-g -I. -I$(ICE_HOME)/include -std=c++11
LDFLAGS=-L$(ICE_HOME)/lib

all: MatrixProcessor MatrixClient MatrixCollector generate 
	mv MatrixProcessor MatrixClient MatrixCollector generate bin/

MatrixProcessor: LDLIBS=-lm -lIce -lFreeze -lIceUtil -lstdc++ -lpthread -lrt -lIceGrid -lGlacier2
MatrixProcessor: MatrixProcessor.o CannonI.o  Cannon.o Modify.o

MatrixClient: LDLIBS=-lm -lIce -lIceUtil -lstdc++ -lpthread -lrt -lIceGrid -lGlacier2
MatrixClient: MatrixClient.o CannonI.o Cannon.o Loader.o Dispatch.o Modify.o 

MatrixCollector: LDLIBS = -lm -lIce -lIceUtil -lstdc++ -lpthread -lIceGrid -lGlacier2
MatrixCollector: MatrixCollector.o CannonI.o Cannon.o Modify.o

generate: generate.cpp

clean:
	$(RM) -rf  bin/* *~ *.o

ejecuteClient:
	./bin/MatrixClient resources/matrizA.m resources/matrizB.m resources/nproc.m --Ice.Config=config/locator.cfg

deploy:
	icepatch2calc bin/.

