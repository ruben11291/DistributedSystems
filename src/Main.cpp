//============================================================================
// Name        : Main.cpp
// Author      : Ruben Perez Pascual
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <Loader.hpp>
#include <Modify.hpp>
#include <Dispatcher.hpp>


using namespace std;
const int Order_p=5;

int main(int argc,char**argv) {
	if(argc != 4){
		cout << "Error."<<endl<<" Use ./bin/multcannon <file_m1> <file_m2> <file_nproc>"<<endl;
		return -1;
	}
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

	Dispatcher dispatcher(nproc);//create dispatcher for proccesors


	Matrix A = loader.getA();
	Matrix B = loader.getB();


	cout << "MATRIX A"<<endl<<A.toString()<<endl;
	cout << "MATRIX B"<<endl<<B.toString()<<endl;

	Matrix R (A.multiply(B));
	cout << "RESULT MATRIZ"<<endl<<R.toString()<<endl;

	vector <Matrix> vA = Modify::split(A,ord);
	std::vector<Matrix> vB = Modify::split(B,ord);


	vA = Modify::displace_horizontal(vA,ord);
	vB = Modify::displace_vertical(vB,ord);


	 dispatcher.distr(vA,vB);
	 dispatcher.run();
	 std::vector<Matrix> res = dispatcher.getResult();
	 cout <<" CANNON RESULT "<<endl;
	 for(auto x:res){
	 	cout << x.toString();
	 }


	return 0;
}
