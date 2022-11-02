#ifndef MAKEMATRIX2
#define MAKEMATRIX2
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <thread>
#include <numeric>

#include "Pixel.hpp"

using namespace std;

class MakeMatrix2{
	private:
        int numFuncs; // range of indices (4 functions means indices 0-3 will be present)
        int numSamples; // # of vectors for the total vect to be split into
		int sideLen; // the number of bins per side of the 2d hist matrix
        int matSize; // the total number of bins (sideLen *sideLen)
        vector<vector<float>> colors; // RGBA values associated with each function index
        vector<vector<float>> data; // all of the data NOT seperated by samples before manipulation
        vector<vector<vector<float>>> data2; // all of the data SEPERATED by samples before manipulation
		Pixel *colMat; // the x,y,RGBA vals for each point after manipulation
		vector<vector<vector<vector<float>>>> allData; // the data vector added to by each thread, to be compacted
		void compileData();
		void compileData2(vector<vector<float>> data, int index); // takes in data from a single sample at a time
		void samplesToCompiler(vector<vector<vector<float>>> data2); // creates a thread for each sample
		void compactData(vector<vector<vector<vector<float>>>> allData); // compacts the multithreaded data
	public:
		// MakeMatrix(int numFuncs, int numSamples, int sideLen, vector<vector<vector<float>>> data2);
		MakeMatrix2(int numFuncs, int numSamples, int sideLen, vector<vector<float>> data, Pixel *mat);
		MakeMatrix2() = default; // pass in default constructor
		~MakeMatrix2() = default;
		Pixel* getMatrix();
};

#endif
