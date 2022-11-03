#include "../headers/RandChoice.hpp"

// initializes a vect<vect<float>> of randomly ordered indices
RandChoice::RandChoice(int numFuncs_, int numPoints_, int numSamples_) {
    numFuncs = numFuncs_;
    numPoints = numPoints_;
    numSamples = numSamples_;
    for (int g=0; g<numSamples; g++) {
        vector<int> interMed(floor(numPoints /numSamples),0);
        samples.push_back(interMed);
    }
    threadSafe_Sample();
}

// fills individual samples with randomly ordered indices
void RandChoice::getRandomValue(unsigned int seeder, int index) {
    std::mt19937 gen(seeder);
    std::uniform_int_distribution<int> dist(16,numFuncs);
    
    // fill an entire column (one sample)
    for (int k=0; k<(numPoints /numSamples); k++) {
        samples[index][k] = (dist(gen));
    }
}

// safely multithreads each sample and assigns unique seed to quickly create vects
void RandChoice::threadSafe_Sample() {
    vector<thread> tasks;
    
    for (int j=0; j<numSamples; j++) {
        unsigned int seeder = (unsigned int) time(NULL);
        tasks.push_back(thread(&RandChoice::getRandomValue, this, seeder, j));
    }
    for (unsigned int f=0; f<tasks.size(); f++) {
        tasks[f].join();
    }
}

// returns individual samples
vector<vector<int>> RandChoice::getSample() {
    return samples;
}
