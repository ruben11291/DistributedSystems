#include <fstream>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
int main(int argc, char**argv){
	assert(argc == 3);
	int a,b;
	string ruta="resources/";
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	ofstream fa((ruta+string("matrizA.m")).c_str());
	ofstream fb((ruta+string("matrizB.m")).c_str());

	fa << a <<endl;
	fb << b <<endl; 

	for ( int i = 0; i < a*a; i++){
	  if(i%a == 0 and i != 0) fa << endl;	
	  fa << i<<" " ;
 	}
	for ( int i = 0; i < b*b; i++){
	  if(i%b == 0 and i != 0) fb << endl;	
	  fb << i<<" " ;
 	}
	fa << endl;
	fb <<endl;
	
	fa.close();
	fb.close();
	return 0;
}
