CC = g++
LIBS = -lm
CFLAGS=-ggdb -std=c++0x
INCLUDE = -I ./include/
SRC = ./src
OBJ = ./obj
HEAD=./include
BIN=./bin
RES=./resources
M1=matriz1.m
M2=matriz2.m
N=nproc.m
EXEC=multcannon


# Link ----------------------------------
Main: $(OBJ)/Main.o $(OBJ)/Loader.o $(OBJ)/Processor.o $(OBJ)/Modify.o $(OBJ)/Matrix.o
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDE) $(OBJ)/Loader.o $(OBJ)/Processor.o $(OBJ)/Modify.o $(OBJ)/Main.o $(OBJ)/Matrix.o -o $(BIN)/$(EXEC) 


# Compilation ---------------------------
$(OBJ)/Main.o: $(SRC)/Main.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/Main.cpp -o $(OBJ)/Main.o

$(OBJ)/Matrix.o: $(SRC)/Main.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/Matrix.cpp -o $(OBJ)/Matrix.o

$(OBJ)/Loader.o: $(SRC)/Loader.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/Loader.cpp -o $(OBJ)/Loader.o
	
$(OBJ)/Processor.o: $(SRC)/Processor.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/Processor.cpp -o $(OBJ)/Processor.o

$(OBJ)/Modify.o: $(SRC)/Modify.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/Modify.cpp -o $(OBJ)/Modify.o
	
clean:
	rm -f $(OBJ)/*.o $(SRC)/*~ ./include/*~ ./*~ $(BIN)/*
execute:
	./$(BIN)/$(EXEC) $(RES)/$(M1) $(RES)/$(M2) $(RES)/$(N)

