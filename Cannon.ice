
module Cannon{
	
	sequence <double> DoubleSeq;
	struct Matrix{
		int ncols;
		DoubleSeq data;
	};

	interface Collector{
		void injectSubmatrix(int row, int col,int order, Matrix m);
	};
	
	interface Processor{
		void init(int row, int col, Processor * up, Processor * left, int order, Collector *target);
		void injectMatrix(Matrix a, Matrix b, int step);
	};

};