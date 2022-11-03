#ifndef FUNCS
#define FUNCS
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <thread>

/**
 * @brief Class that defines functions to be chosen from
 * and implemented in the fractal generator 
 */
class Funcs{
    private:
        float calcRSqr(float xVal, float yVal);
        float calcR(float rSqrVal);
        float calcThet(float xVal, float yVal);
    public:
        std::vector<float> f0(std::vector<float> xyVals);
        std::vector<float> f1(std::vector<float> xyVals);
        std::vector<float> f2(std::vector<float> xyVals);
        std::vector<float> f3(std::vector<float> xyVals);
        std::vector<float> f4(std::vector<float> xyVals);
	std::vector<float> f5(std::vector<float> xyVals);
        std::vector<float> f6(std::vector<float> xyVals);
        std::vector<float> f7(std::vector<float> xyVals);
        std::vector<float> f8(std::vector<float> xyVals);
	std::vector<float> f9(std::vector<float> xyVals);
        std::vector<float> f10(std::vector<float> xyVals);
        std::vector<float> f11(std::vector<float> xyVals);
        std::vector<float> f12(std::vector<float> xyVals);
        std::vector<float> f13(std::vector<float> xyVals);
        std::vector<float> f14(std::vector<float> xyVals);
        std::vector<float> f15(std::vector<float> xyVals);
        std::vector<float> f16(std::vector<float> xyVals);
        std::vector<float> f17(std::vector<float> xyVals);
        std::vector<float> f18(std::vector<float> xyVals);
};

typedef std::vector<float>(Funcs::*vecFuncs)(std::vector<float> xyVals);

#endif
