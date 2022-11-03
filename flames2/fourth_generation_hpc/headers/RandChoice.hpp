#ifndef RANDCHOICE
#define RANDCHOICE
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <thread>
#include <numeric>

using namespace std;

/**
 *  Class that models a sequence of i.i.d. standard gaussians
 *  vector of distributions that can be sampled with random seeds, giving
 *  a model of uncorrelated Gaussian variables.
 */
class RandChoice{
	private:
        int numFuncs; // range of indices (4 functions means indices 0-3 will be present)
		int numPoints; // total # of points to plot (length of the total random vect)
        int numSamples; // # of vectors for the total vect to be split into
		vector<vector<int>> samples; // a large vect of rand ordered indices split into shorter vects
		void threadSafe_Sample();
		void getRandomValue(unsigned int seed, int index);
	public:
		RandChoice(int numFuncs_, int numPoints_, int numSamples_);
		RandChoice() = default; // pass in default constructor
		~RandChoice() = default;
		vector<vector<int>> getSample();
};

#endif
