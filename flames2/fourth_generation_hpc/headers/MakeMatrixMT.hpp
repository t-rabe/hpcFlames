#ifndef MAKEMATRIXMT
#define MAKEMATRIXMT
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <thread>
#include <numeric>

#include "Pixel.hpp"
#include "PixelInt.hpp"

using namespace std;

class MakeMatrixMT{
	private:
        int numFuncs; // range of indices (4 functions means indices 0-3 will be present)
        int numSamples; // # of vectors for the total vect to be split into
		int sideLen; // the number of bins per side of the 2d hist matrix
        int matSize; // the total number of bins (sideLen *sideLen)
        float alphMax; // the largest bin count
        bool withAlph;
        vector<vector<float>> colors; // RGBA values associated with each function index
        vector<vector<float>> data; // all of the data NOT seperated by samples before manipulation
        vector<vector<vector<float>>> data2; // all of the data SEPERATED by samples before manipulation 
        PixelInt *colMat; // the x,y,RGBA vals for each point after manipulation
        Pixel *newColMat; // float version of colMat vals
		PixelInt **allData; // the data vector added to by each thread, to be compacted
        // void (MakeMatrix3::*colFunc)(int,int);
		void compileData2(vector<vector<float>> data, int index); // takes in data from a single sample at a time
		void samplesToCompiler(); // creates a thread for each sample
		void compactData(); // compacts the multithreaded data
	public:
		// MakeMatrix(int numFuncs, int numSamples, int sideLen, vector<vector<vector<float>>> data2);
		MakeMatrixMT(int numFuncs_, int numSamples_, int sideLen_, vector<vector<vector<float>>> data_, bool includeAlph_);
		MakeMatrixMT() = default; // pass in default constructor
		~MakeMatrixMT() = default;
        void normAsFloat3();
        void noNorm();
		PixelInt* getMatrix();
        Pixel* getMatrixNormAsFloat3();
        Pixel* getMatrixNoNorm();
};

#endif
