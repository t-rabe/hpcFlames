#include "../headers/MakeMatrix.hpp"

MakeMatrix::MakeMatrix(int numFuncs_, int numSamples_, int sideLen_, vector<vector<float>> data_, bool includeAlph_) {
    numFuncs = numFuncs_;
    numSamples = numSamples_;
    sideLen = sideLen_;
    data = data_;
    matSize = sideLen_ *sideLen_;
    colMat = new PixelInt[matSize];
    newColMat = new Pixel[matSize];
    colors = {{10,5,0},{0,0,10},{10,0,10},{0,10,0},{10,0,0},
                {10,10,0},{0,10,10},{10,0,0},{0,10,0},{0,5,10},
		        {10,5,0},{10,0,0},{10,7,0},{10,3,0},{10,5,0},
		        {0,0,10},{2,0,10},{0,0,10},{0,2,10}};
    compileData();
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

// compiles data without multithreading
void MakeMatrix::compileData() {
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
        colMat[binNum].r += colors[colInd][0];
        colMat[binNum].g += colors[colInd][1];
        colMat[binNum].b += colors[colInd][2];
        colMat[binNum].a ++;
    }
}

void MakeMatrix::normAsFloat3() {
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

void MakeMatrix::noNorm() {
    for (int n=0; n<matSize; n++) {
        newColMat[n].r = std::min(1.0,(colMat[n].r / 10.0));
        newColMat[n].g = std::min(1.0,(colMat[n].g / 10.0));
        newColMat[n].b = std::min(1.0,(colMat[n].b / 10.0));
        // THIS SETS THE BACKGROUND COL TO 0.5 alpha
        newColMat[n].a = min(1.0,(0.5 *colMat[n].a));
    }
}

PixelInt* MakeMatrix::getMatrix() {
    return colMat;
}

Pixel* MakeMatrix::getMatrixNormAsFloat3() {
    normAsFloat3();
    return newColMat;
}

Pixel* MakeMatrix::getMatrixNoNorm() {
    noNorm();
    return newColMat;
}