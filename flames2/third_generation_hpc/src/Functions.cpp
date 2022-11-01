#include "../headers/Functions.hpp"

float Funcs::calcRSqr(float xVal, float yVal) {
    float r = pow(xVal,2) + pow(yVal,2);
    return r;
}

float Funcs::calcR(float rSqrVal) {
    return sqrt(rSqrVal);
}

float Funcs::calcThet(float xVal, float yVal) {
    float thet = atan(xVal / yVal);
    return thet;
}

std::vector<float> Funcs::f0(std::vector<float> xyVals) {
    std::vector<float> temp;
    temp.push_back(xyVals[0]);
    temp.push_back(xyVals[1]);
    return temp;
}

std::vector<float> Funcs::f1(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    float r = calcR(r2);

    std::vector<float> temp;
    temp.push_back(xVal / r);
    temp.push_back(yVal / r);
    return temp;
}

std::vector<float> Funcs::f2(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    float r = calcR(r2);

    std::vector<float> temp;
    temp.push_back(xVal / r);
    temp.push_back(yVal / r);
    return temp;
}

std::vector<float> Funcs::f3(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    

    float x = (xVal *sin(r2)) - (yVal *cos(r2));
    float y = (xVal *cos(r2)) + (yVal *sin(r2));
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f4(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    float r = calcR(r2);

    float x = (2 *yVal) / (r + 1);
    float y = (2 *xVal) / (r + 1);
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f5(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);

    float x = (xVal *sin(r2)) - (xVal *cos(r2));
    float y = (yVal *cos(r2)) + (yVal *sin(r2));
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f6(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);

    float x = (yVal *sin(r2)) - (yVal *cos(r2));
    float y = (xVal *cos(r2)) + (xVal *sin(r2));
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f7(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    float r = calcR(r2);

    std::vector<float> temp;
    float x = xVal / r;
    float y = yVal / r2;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f8(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    float r = calcR(r2);

    std::vector<float> temp;
    float x = xVal / r2;
    float y = yVal / r;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f9(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    

    float x = (xVal *sin(r2)) - (yVal *cos(r2));
    float y = (x *cos(r2)) + (yVal *sin(r2));
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f10(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    float r = calcR(r2);

    float x = (2 *yVal) / (r + 1);
    float y = (2 *x) / (r + 1);
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f11(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    

    float x = (xVal *sin(r2)) - (yVal *cos(r2));
    float y = (x *cos(r2)) + (yVal *sin(r2));
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f12(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    float r = calcR(r2);

    float x = (2 *yVal) / (r + 1);
    float y = (2 *x) / (r + 1);
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f13(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);

    float x = (xVal *sin(r2)) - (xVal *cos(r2));
    float y = (yVal *sin(r2)) + (yVal *cos(r2));
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f14(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);

    float x = (yVal *sin(r2)) - (yVal *cos(r2));
    float y = (x *sin(r2)) + (x *cos(r2));
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f15(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    float r = calcR(r2);

    std::vector<float> temp;
    temp.push_back(xVal / r);
    temp.push_back(yVal / r);
    return temp;
}

std::vector<float> Funcs::f16(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);

    std::vector<float> temp;
    temp.push_back(xVal / r2);
    temp.push_back(yVal / r2);
    return temp;
}

std::vector<float> Funcs::f17(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);

    float x = (xVal *sin(r2)) - (yVal *cos(r2));
    float y = (x *cos(r2)) + (yVal *sin(r2));
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}

std::vector<float> Funcs::f18(std::vector<float> xyVals) {
    float xVal = xyVals[0];
    float yVal = xyVals[1];
    float r2 = calcRSqr(xVal,yVal);
    float r = calcR(r2);
    float thet = calcThet(xVal, yVal);
	
    float x = (r *sin(thet +r));
    float y = (r *cos(thet -r));
    std::vector<float> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}
