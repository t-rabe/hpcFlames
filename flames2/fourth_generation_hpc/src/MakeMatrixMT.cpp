#include "../headers/MakeMatrixMT.hpp"

MakeMatrixMT::MakeMatrixMT(int numFuncs_, int numSamples_, int sideLen_, vector<vector<vector<float>>> data_, bool includeAlph_) {
    numFuncs = numFuncs_;
    numSamples = numSamples_;
    sideLen = sideLen_;
    data2 = data_;
    matSize = sideLen_ *sideLen_;
    colMat = new PixelInt[matSize];
    newColMat = new Pixel[matSize];
    withAlph = includeAlph_;
    allData = new PixelInt*[numSamples];
    colors = {{10,5,0},{0,0,10},{10,0,10},{0,10,0},{10,0,0},
                {10,10,0},{0,10,10},{10,0,0},{0,10,0},{0,5,10},
		        {10,5,0},{10,0,0},{10,7,0},{10,3,0},{10,5,0},
		        {0,0,10},{2,0,10},{0,0,10},{0,2,10}};
    samplesToCompiler();
    compactData();
    int alphMaxInt = 1;
    if (withAlph) {
        for (int f=0; f<matSize; f++) {
            if (colMat[f].a > alphMaxInt) {
                alphMaxInt = colMat[f].a;
            }
        }
    }
    alphMax = alphMaxInt *1.0;
}

void MakeMatrixMT::normAsFloat3() {
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

void MakeMatrixMT::noNorm() {
    for (int n=0; n<matSize; n++) {
        newColMat[n].r = std::min(1.0,(colMat[n].r / 10.0));
        newColMat[n].g = std::min(1.0,(colMat[n].g / 10.0));
        newColMat[n].b = std::min(1.0,(colMat[n].b / 10.0));
        // THIS SETS THE BACKGROUND COL TO 0.5 alpha
        newColMat[n].a = min(1.0,(0.5 *colMat[n].a));
    }
}

// compiles data with multithreading.. Needs to be added together using compactData()
void MakeMatrixMT::compileData2(vector<vector<float>> data, int index) {
    int halfSide = sideLen /2;
    PixelInt *sampleColMat = new PixelInt[matSize];
    for (unsigned int i=0; i<data.size(); i++) {
    // CHANGE TO "*halfside /2" TO RETURN TO ORIGINAL (SMALLER) WINDOW
        int xBin = max(min(int(data[i][0] *halfSide /2.5),halfSide) +halfSide -1,0);
        int yBin = max(min(int(data[i][1] *halfSide /2.5),halfSide) +halfSide -1,0);
        int binNum = (sideLen *xBin) +yBin;
        int colInd = data[i][2];
        sampleColMat[binNum].r += colors[colInd][0];
        sampleColMat[binNum].g += colors[colInd][1];
        sampleColMat[binNum].b += colors[colInd][2];
        sampleColMat[binNum].a ++;
    }
    
    allData[index] = sampleColMat;
}

// assigns each sample to a thread and passes it to the compileData2() function
void MakeMatrixMT::samplesToCompiler() {
    vector<thread> tasks;

    for (unsigned int j=0; j<data2.size(); j++) {
        int ind = (int) (j);
        tasks.push_back(thread(&MakeMatrixMT::compileData2, this, data2[ind], ind));
    }
    for (unsigned int f=0; f<tasks.size(); f++) {
        tasks[f].join();
    }
}

// combines the various dataMat from each sample by summing element-wise
// NOTE: change the constants in subtraction to account for background color settings
void MakeMatrixMT::compactData() {
    for (int p=0; p<matSize; p++) {
        for (int s=0; s<numSamples; s++) {
            colMat[p].r += allData[s][p].r;
            colMat[p].g += allData[s][p].g;
            colMat[p].b += allData[s][p].b;
            colMat[p].a += allData[s][p].a;
        }
        // colMat[p].r -= (numSamples *1.0);
        // colMat[p].g -= (numSamples *1.0);
        // colMat[p].b -= (numSamples *1.0);
        colMat[p].a -= (numSamples *1.0);
    }
}

PixelInt* MakeMatrixMT::getMatrix() {
    return colMat;
}

Pixel* MakeMatrixMT::getMatrixNormAsFloat3() {
    normAsFloat3();
    return newColMat;
}

Pixel* MakeMatrixMT::getMatrixNoNorm() {
    noNorm();
    return newColMat;
}