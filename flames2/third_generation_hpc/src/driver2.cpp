int fileNumInt = 0;
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
#include "../headers/MakeMatrix2.hpp"
#include "../headers/Pixel.hpp"

using namespace std;

int main() {
    string fileNum = to_string(fileNumInt);
    auto start = std::chrono::high_resolution_clock::now();
    cout << "Start file # " << fileNum << endl;
    ofstream outfile;
    
    string fileName = "../output/16_18Test" + fileNum + ".bin";
    int num1 = 18; // number of functions
    int num2 = 100000000; // number of points
    int num3 = 16; // number of samples
    int num4 = num2 - (num2 %num3); // the closest multiple of the # of samples
    int num5 = 9000; // sideLen of the matrix
    int num6 = (num5 *num5); // total number of bins
    
    Pixel *colorMat = new Pixel[num6];
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
    MakeMatrix2 *makematrix = new MakeMatrix2(num1,num3,num5,applyfuncs->getData(),colorMat);
    delete applyfuncs;

    // Pixel *colorMat = new Pixel[num6];
    // cout << "Making matrix..." << endl;
    colorMat = makematrix->getMatrix();
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
        // const int imgWidth = 9000;
        // const int imgHeight = 9000;
        // fwrite(&imgWidth, sizeof(imgWidth), 1, f);
        // fwrite(&imgHeight, sizeof(imgHeight), 1, f);

        // for (int i=0; i<num6; ++i)
        // {
        //     fwrite(&colorMat[i], sizeof(struct Pixel), 1, f);
        // }
        fwrite(colorMat, sizeof(struct Pixel), num6, f);
    }

    fclose(f);
    delete colorMat;
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::seconds>(end2-end);
    cout << "Write time: " << duration2.count() << " s\n" << "End file # " << fileNum << "\n";

    return 0;
}
