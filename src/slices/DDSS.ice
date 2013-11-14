#pragma once

module DDSS{
	sequence<double> DoubleSeq;

	struct Matrix{
		int ncols;
		DoubleSeq data;
	};

	interface Collector{
		void injectSubmatrix(Matrix m, int row, int col);
	};
	interface Processor{
		void init(int row, int col, Processor * above, Processor *left , int order, Collector *target);
		void injectFisrt(Matrix a, int step);
		void injectSecond(Matrix b, int step);
	};

	interface Operations{
		Matrix matrixMultiply(Matrix a, Matrix b);
	};
};