
#include <Modify.hpp>

vector<Matrix> Modify::mod(const Matrix &m,int nproc){
	std::vector<Matrix> v;
	for(int i=0;i<m.fil;i+=m.col/nproc){
		for(int j =0;j<m.col;j+=m.col/nproc){
			Matrix aux(m.fil/nproc,m.col/nproc);
			for(int l=0;l<m.fil/nproc;l++){
				for(int k=0;k<m.col/nproc;k++){
					// cout << "l "<<l<< " k "<<k<<" i+l "<<i+l<<" j+k "<<j+k<<endl;
					aux.data[l][k] = m.data[i+l][j+k];
				}
			}
			v.push_back(aux);
		}
	}
	return v;
}