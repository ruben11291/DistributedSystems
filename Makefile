CXXFLAGS=-g -I. -I$(ICE_HOME)/include -std=c++11
LDFLAGS=-L$(ICE_HOME)/lib

all: MatrixProcessor MatrixClient MatrixCollector generate
	mv *.o obj/ 
	mv MatrixProcessor MatrixClient MatrixCollector generate bin/

MatrixProcessor: LDLIBS=-lm -lIce -lFreeze -lIceUtil -lstdc++ -lpthread -lrt -lIceGrid -lGlacier2
MatrixProcessor: MatrixProcessor.o CannonI.o  Cannon.o Modify.o

MatrixClient: LDLIBS=-lm -lIce -lIceUtil -lstdc++ -lpthread -lrt -lIceGrid -lGlacier2
MatrixClient: MatrixClient.o CannonI.o Cannon.o Loader.o Dispatch.o Modify.o 

MatrixCollector: LDLIBS = -lIce -lIceUtil -lstdc++ -lpthread -lIceGrid -lGlacier2
MatrixCollector: MatrixCollector.o CannonI.o Cannon.o Modify.o

generate: generate.cpp
gen: 
	./generate 36 36


clean:
	$(RM) *~ *.o MatrixProcessor MatrixClient MatrixCollector generate
	$(RM) *~ *.o *.bz2
	$(RM) -rf db/*

ejecuteClient:
	./MatrixClient resources/matrizA.m resources/matrizB.m resources/nproc.m -n1
ejecuteProcessor:
	./MatrixProcessor
ejecuteCollector:
	./MatrixCollector

deploy:
	icepatch2calc bin/.