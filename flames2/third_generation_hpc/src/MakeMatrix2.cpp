#include "../headers/MakeMatrix2.hpp"

// MakeMatrix::MakeMatrix(int numFuncs, int numSamples, int sideLen, vector<vector<vector<float>>> data2) {
//     this->numFuncs = numFuncs;
//     this->numSamples = numSamples;
//     this->sideLen = sideLen;
//     this->data2 = data2;
//     vector<vector<vector<vector<float>>>> allData(numSamples);
//     this->allData = allData;
//     this->colors = {{1.,0.5,0.,1.},{0.,0.,1.,1.},{1.,0.,1.,1.},{0.,1.,0.,1.},{1.,0.,0.,1.},
//                     {1.,1.,0.,1.},{0.,1.,1.,1.}};
//     this->samplesToCompiler(data2);
//     this->compactData(this->allData);
// }

MakeMatrix2::MakeMatrix2(int numFuncs, int numSamples, int sideLen, vector<vector<float>> data, Pixel *mat) {
    this->numFuncs = numFuncs;
    this->numSamples = numSamples;
    this->sideLen = sideLen;
    this->data = data;
    this->matSize = sideLen *sideLen;
    this->colMat = mat;
    // vector<vector<vector<vector<float>>>> allData(numSamples);
    // this->allData = allData;
    this->colors = {{1.,0.5,0.,1.},{0.,0.,1.,1.},{1.,0.,1.,1.},{0.,1.,0.,1.},{1.,0.,0.,1.},
                    {1.,1.,0.,1.},{0.,1.,1.,1.},{1.,0.,0.,1.},{0.,1.,0.,1.},{0.,0.5,1.,1.},
		    {1.,0.5,0.,1.},{1.,0.,0.,1.},{1.,0.7,0.,1.},{1.,0.3,0.,1.},{1.,0.5,0.,1.},
		    {0.,0.,1.,1.},{0.2,0.,1.,1.},{0.,0.,1.,1.},{0.,0.2,1.,1.}};
    compileData();
}

// compiles data without multithreading
void MakeMatrix2::compileData() {
    int halfSide = sideLen /2;
    // cout << data.size() << endl;
    for (unsigned int i=0; i<data.size(); i++) {
	// CHANGE TO "*halfside /2" TO RETURN TO ORIGINAL (SMALLER) WINDOW
        int xBin = max(min(int(data[i][0] *halfSide /2.5),halfSide) +halfSide -1,0);
        int yBin = max(min(int(data[i][1] *halfSide /2.5),halfSide) +halfSide -1,0);
        int bin = (sideLen *xBin) +yBin;
        colMat[bin].r += colors[data[i][2]][0];
        colMat[bin].g += colors[data[i][2]][1];
        colMat[bin].b += colors[data[i][2]][2];
        colMat[bin].a += colors[data[i][2]][3];
    }
    // return totMat;
}

// compiles data with multithreading.. Needs to be added together using compactData()
void MakeMatrix2::compileData2(vector<vector<float>> data, int index) {
    vector<vector<float>> partMat(sideLen,vector<float>(4,0.0));
    vector<vector<vector<float>>> totMat(sideLen,partMat);
    int halfSide = sideLen /2;
    for (unsigned int i=0; i<data.size(); i++) {
        int xBin = max(min(int(data[i][0] *halfSide /2),halfSide) +halfSide -1,0);
        int yBin = max(min(int(data[i][1] *halfSide /2),halfSide) +halfSide -1,0);
        for (int k=0; k<4; k++) {
            totMat[xBin][yBin][k] += colors[data[i][2]][k];
        }
    }
    allData[index] = totMat;
}

// assigns each sample to a thread and passes it to the compileData2() function
void MakeMatrix2::samplesToCompiler(vector<vector<vector<float>>> data2) {
    vector<thread> tasks;

    for (unsigned int j=0; j<data2.size(); j++) {
        int ind = (int) (j);
        tasks.push_back(thread(&MakeMatrix2::compileData2, this, data2[ind], ind));
    }
    for (unsigned int f=0; f<tasks.size(); f++) {
        tasks[f].join();
    }
}

// combines the various dataMat from each sample by summing element-wise
void MakeMatrix2::compactData(vector<vector<vector<vector<float>>>> allData) {
    vector<vector<float>> partMat2(sideLen,vector<float>(4,0.0));
    vector<vector<vector<float>>> tempTot(sideLen,partMat2);
    for (int k=0; k<sideLen; k++) {
        for (int m=0; m<sideLen; m++) {
            for (int s=0; s<numSamples; s++) {
                for (int l=0; l<4; l++) {
                    tempTot[k][m][l] += allData[s][k][m][l];
                }
            }
        }
    }
    // this->outData=tempTot;
}

Pixel* MakeMatrix2::getMatrix() {
    return colMat;
}
