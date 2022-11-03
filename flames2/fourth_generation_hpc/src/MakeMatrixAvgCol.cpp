#include "../headers/MakeMatrixAvgCol.hpp"

MakeMatrixAvg::MakeMatrixAvg(int numFuncs_, int numSamples_, int sideLen_, vector<vector<float>> data_, bool includeAlph_) {
    numFuncs = numFuncs_;
    numSamples = numSamples_;
    sideLen = sideLen_;
    data = data_;
    matSize = sideLen_ *sideLen_;
    colMat = new Pixel[matSize];
    newColMat = new Pixel[matSize];
    colors = {{1.0,0.5,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0},
                {1.0,1.0,0.0},{0.0,1.0,1.0},{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.5,1.0},
		        {1.0,0.5,0.0},{1.0,0.0,0.0},{1.0,0.7,0.0},{1.0,0.3,0.0},{1.0,0.5,0.0},
		        {0.0,0.0,1.0},{0.2,0.0,1.0},{0.0,0.0,1.0},{0.0,0.2,1.0}};
    compileDataAveraging();
    int alphMaxInt = 1;
    if (includeAlph_) {
        for (int f=0; f<matSize; f++) {
            if (colMat[f].a > alphMaxInt) {
                alphMaxInt = colMat[f].a;
            }
        }
    }
    alphMax = alphMaxInt *1.0;
}

// compiles data BY DIVIDING EVERYTIME A NEW COLOR IS ADDED
void MakeMatrixAvg::compileDataAveraging() {
    int halfSide = sideLen /2;
    int binNum = 0;
    int xBin = 0;
    int yBin = 0;
    int colInd = 0;
    for (unsigned int i=0; i<data.size(); i++) {
    // CHANGE TO "*halfside /2" TO RETURN TO ORIGINAL (SMALLER) WINDOW
        xBin = max(min(int(data[i][0] *halfSide /2.5),halfSide) +halfSide -1,0);
        yBin = max(min(int(data[i][1] *halfSide /2.5),halfSide) +halfSide -1,0);
        binNum = (sideLen *xBin) +yBin;
        colInd = data[i][2];
        colMat[binNum].a ++;
        colMat[binNum].r = (colMat[binNum].r + colors[colInd][0]) / 2;
        colMat[binNum].g = (colMat[binNum].g + colors[colInd][1]) / 2;
        colMat[binNum].b = (colMat[binNum].b + colors[colInd][2]) / 2;
    }
}

void MakeMatrixAvg::normAsFloat3() {
    float divideFactor;
    for (int k=0; k<matSize; k++) {
        divideFactor = max((10.0 *(colMat[k].a)),1.0);
        newColMat[k].r = colMat[k].r / divideFactor;
        newColMat[k].g = colMat[k].g / divideFactor;
        newColMat[k].b = colMat[k].b / divideFactor;
        // newColMat[k].a = colMat[k].a / alphMax;
        newColMat[k].a = 1.0;
    }
}

void MakeMatrixAvg::noNorm() {
    for (int n=0; n<matSize; n++) {
        // newColMat[n].r = std::min(1.0,(colMat[n].r / 10.0));
        // newColMat[n].g = std::min(1.0,(colMat[n].g / 10.0));
        // newColMat[n].b = std::min(1.0,(colMat[n].b / 10.0));
        // // THIS SETS THE BACKGROUND COL TO 0.5 alpha
        // newColMat[n].a = min(1.0,(1.0 *colMat[n].a));
        newColMat[n].r = colMat[n].r;
        newColMat[n].g = colMat[n].g;
        newColMat[n].b = colMat[n].b;
        newColMat[n].a = 1.0;
    }
}

Pixel* MakeMatrixAvg::getMatrix() {
    return colMat;
}

Pixel* MakeMatrixAvg::getMatrixNormAsFloat3() {
    normAsFloat3();
    return newColMat;
}

Pixel* MakeMatrixAvg::getMatrixNoNorm() {
    noNorm();
    return newColMat;
}