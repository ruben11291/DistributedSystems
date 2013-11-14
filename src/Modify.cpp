/*
 * Modify.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ruben
 */

#include <Modify.hpp>

std::vector<Matrix> Modify::split(const Matrix &m,int ord){
	std::vector<Matrix> v;

	for(int a = 0; a< m.ncol*m.ncol; a+=m.ncol*(m.ncol/ord)){
		for(int i = a; i< m.ncol+a; i+=m.ncol/ord){
			Matrix aux (m.ncol/ord);
			aux.data = std::vector<double> ();
			for( int j= 0; j< m.ncol/ord; j++){
				for(int k = i ; k< m.ncol/ord+i; k++)
					aux.data.push_back(m.data[j*m.ncol + k] );
			}
			v.push_back(aux);
		}
}
	// for(int i=0;i<m.;i+=m.ncol/ord){
	// 	for(int j =0;j<m.col;j+=m.col/ord){
	// 		Matrix aux(m.fil/ord,m.col/ord);
	// 		for(int l=0;l<m.fil/ord;l++){
	// 			for(int k=0;k<m.col/ord;k++){
	// 				// cout << "l "<<l<< " k "<<k<<" i+l "<<i+l<<" j+k "<<j+k<<endl;
	// 				aux.data[(l*m.col)+k] = m.data[(i+(l*m.col)) + j+k];
	// 			}
	// 		}
	// 		v.push_back(aux);
	// 	}
	// }
	return v;
}

std::vector<Matrix> Modify::displace_horizontal(const vector<Matrix> &m,int ord){
	std::vector<Matrix> v;
	int count = 0;
	for(int i = 0;i < m.size(); i+=ord){
		for(int j = i+count; j < i+ord; j++)
			v.push_back(m[j]);
		for(int j = i; j< i+count ; j++)
			v.push_back(m[j]);
		count++;
	}
	return v;
}
std::vector<Matrix>  Modify::displace_vertical(const std::vector<Matrix>& m,int ord){
	std::vector<Matrix> v,aux;

	for(int i = 0;i<ord;i++){
		for(int j = i; j<ord ; j++)
			v.push_back(m [ i + j * ord ] );
		for(int j = 0; j<i ; j++)
			v.push_back(m [ i + j * ord ] );
	}

	for(int i = 0; i < ord; i++)
		for( int j = 0; j < ord; j++)
			aux.push_back(v[ j * ord + i ]);

	return aux;
}