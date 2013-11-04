//============================================================================
// Name        : Main.cpp
// Author      : Ruben Perez Pascual
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <Loader.hpp>
#include <fstream>
#include <Modify.hpp>
// #include <Dispatcher.hpp>

int read_nproc(char *file);


using namespace std;
const int Order_p=5;

int main(int argc,char**argv) {
	if(argc != 4){
		cout << "Error."<<endl<<" Use ./bin/multcannon <file_m1> <file_m2> <file_nproc>"<<endl;
		return -1;
	}
	Loader loader;
	int nproc;
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
	
	// Dispatcher disp;

	if(!loader.can_mult()){
		cout<<"Error with matrix dimension"<<endl;
		return -1;
	}
	Matrix A = loader.getA();
	Matrix B = loader.getB();
	if(A.fil%nproc != 0 or A.col%nproc != 0){
		cout << "Error with matrix A dimension"<<endl<<"Must be mult of nproccessor"<<endl;
		return -1;
	}
	if(B.fil % nproc != 0 or B.col % nproc !=0){
		cout << "Error with matrix B dimension"<<endl<<"Must be mult of nproccessor"<<endl;
		return -1;
	}

	cout << "MATRIX A"<<endl<<A.toString()<<endl;
	cout << "MATRIX B"<<endl<<B.toString()<<endl;

	Matrix R (A.multiply(B));
	cout << "RESULT MATRIZ"<<endl<<R.toString()<<endl;

	vector <Matrix> vA = Modify::mod(A,nproc);
	std::vector<Matrix> vB = Modify::mod(B,nproc);

	 cout << "A"<<endl;
	 for (int i=0;i<vA.size();i++){
		cout <<vA[i].toString();
		if(i%nproc==0) cout<<endl;
		else cout<<" ";
	}
	 cout<<" B" <<endl;
	 for(int i=0;i<vB.size();i++)
	 	cout<<vB[i].toString()<<endl;
	


	return 0;
}

int read_nproc(char *file){
	ifstream np(file);
	int nproc;
	np >>nproc;
	np.close();
	return nproc;
}