// int fileNumInt = 2;
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <thread>
#include <functional>
#include <fstream>

#include "../headers/Functions.hpp"
#include "../headers/RandChoice.hpp"
#include "../headers/ApplyFuncs.hpp"
#include "../headers/MakeMatrix.hpp"
#include "../headers/Pixel.hpp"
#include "../headers/PixelInt.hpp"

using namespace std;

int main(int argc, char *argv[]) {
//    string fileNum = to_string(fileNumInt);
    string fileNum = argv[1];
    auto start = std::chrono::high_resolution_clock::now();
    cout << "Start file # " << fileNum << endl;
    ofstream outfile;
    
    string fileName = "../output/testDriver3" + fileNum + ".bin";
    bool includingAlpha = false;
    int num1 = 18; // number of functions
    int num2 = 100000000; // number of points
    int num3 = 16; // number of samples
    int num4 = num2 - (num2 %num3); // the closest multiple of the # of samples
    int num5 = 3000; // sideLen of the matrix
    int num6 = (num5 *num5); // total number of bins
    
    // PixelInt *colorMat = new PixelInt[num6];
    Pixel *floatColorMat;
    // Pixel *colorMatSplit = new Pixel[num3][num6];
    Funcs funcs;
    vecFuncs a[] = {&Funcs::f0,&Funcs::f1,&Funcs::f2,&Funcs::f3,&Funcs::f4,&Funcs::f5,&Funcs::f6,&Funcs::f7,&Funcs::f8,&Funcs::f9,&Funcs::f10,
			&Funcs::f11,&Funcs::f12,&Funcs::f13,&Funcs::f14,&Funcs::f15,&Funcs::f16,
			&Funcs::f17,&Funcs::f18};
    
    cout << "Getting random choices..." << endl;
    RandChoice *randchoice = new RandChoice(num1,num4,num3);

    cout << "Applying functions..." << endl;
    ApplyFuncs *applyfuncs = new ApplyFuncs(randchoice->getSample(),a,funcs);
    delete randchoice;
    
    cout << "Making matrix..." << endl;
    MakeMatrix *makematrix = new MakeMatrix(num1,num3,num5,applyfuncs->getData(),includingAlpha);
    delete applyfuncs;
    // delete colorMat;

    // Pixel *colorMat = new Pixel[num6];
    // cout << "Making matrix..." << endl;
    floatColorMat = makematrix->getMatrixNoNorm();
    delete makematrix;
    // MakeMatrix makematrix(num1,num3,num5,applyfuncs.getData2());
    // vector<vector<vector<vector<float>>>> finMat = makematrix.getMatrix2();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end-start);
    cout << "Number of points: " << num2 << endl;
    cout << "Sidelength of matrix: " << num5 << endl << "Number of threads: " << num3 << endl 
	<< "Generation runtime: " << duration.count() << " s" << endl;
    
    FILE* f = fopen(fileName.c_str(), "wb");

    if (f) {
        fwrite(floatColorMat, sizeof(struct Pixel), num6, f);
    }

    fclose(f);
    delete floatColorMat;
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::seconds>(end2-end);
    cout << "Write time: " << duration2.count() << " s\n" << "End file # " << fileNum << "\n";

    return 0;
}
