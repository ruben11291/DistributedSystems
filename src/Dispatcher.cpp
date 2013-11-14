
#include <Dispatcher.hpp>

Dispatcher::Dispatcher(int npro):nproc(npro){
	processor = vector<Processor>(nproc);
	for(int i=0;i<nproc;i++)
		processor[i] = Processor(i,nproc);

}

Dispatcher::~Dispatcher(){

}

void Dispatcher::distr(const vector<Matrix> & mA, const std::vector<Matrix> &mB){
	// for(auto i:mA)
	// 	cout << i.toString()<<endl;
	// cout.flush();
	// for(auto i:mB)
	// 	cout<<i.toString()<<endl;
	// cout.flush();

	for( int i= 0; i < nproc; i++){
		processor[i].setA(mA[i]);
		processor[i].setB(mB[i]);
	}
	// for(int i = 0; i<nproc;i++){
	// 	cout<<" I "<<i<<" Processor "<<processor[i].getId()<< endl;
	// 	for(int j =0;j<processor[i].getA().data.size();j++)
	// 		cout<<processor[i].getA().data[j]<<" ";
	// 	cout<<endl;
	// 	for(int j =0;j<processor[i].getB().data.size();j++)
	// 		cout<<processor[i].getB().data[j]<<" ";
	// 	cout<<endl;
	// }


}

void Dispatcher::run(){
	std::vector<Matrix> auxA,auxB;

	int l = (int)sqrt(nproc);
	for(int i = 0; i < l-1; i++){
		auxA = std::vector<Matrix>();
		auxB = std::vector<Matrix>();
		for( int j = 0; j < nproc; j++){
			processor[j].run();
			auxA.push_back(processor[j].getA());
			auxB.push_back(processor[j].getB());
		}
		for( int j = 0; j < nproc; j++){
			processor[processor[j].getLeft()].setA(auxA[j]);
			processor[processor[j].getNorth()].setB(auxB[j]);
		}

	}
	for( int j = 0; j < nproc; j++)
			processor[j].run();
}

std::vector<Matrix>  Dispatcher::getResult(){
	std::vector<Matrix> v;
	for(int i = 0; i<nproc; i++)
		v.push_back(processor[i].getResult());
	return v;
}
	

int Dispatcher::getNproc(){
	return nproc;
}

vector<Processor> Dispatcher::getProcessor(){
	return processor;
}