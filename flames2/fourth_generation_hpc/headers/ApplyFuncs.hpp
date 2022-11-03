#ifndef APPLYFUNCS
#define APPLYFUNCS
#define _USE_MATH_DEFINES
#define CALL_MEMBER_FN(object,ptrToMember) ((object).*(ptrToMember))

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <thread>
#include <numeric>
#include <functional>

#include "../headers/Functions.hpp"

using namespace std;

class ApplyFuncs{
	private:
        vector<vector<int>> indices; // random index vects
        vector<float> point; // the current point to be re entered into the funcs
		vector<vector<vector<float>>> data; // x,y,col data for each point
		void iterateSample(vector<int> indSample, vecFuncs a[], Funcs funcs, int index); // goes through individual samples
		void assignSamples(vecFuncs a[], Funcs funcs); // assigns each sample to a thread
	public:
		ApplyFuncs(vector<vector<int>> indices_, vecFuncs a[], Funcs funcs);
		ApplyFuncs() = default; // pass in default constructor
		~ApplyFuncs() = default;
		vector<vector<float>> getData(); // returns the final data
        vector<vector<vector<float>>> getData2(); // returns data seperated into samples
};

#endif
