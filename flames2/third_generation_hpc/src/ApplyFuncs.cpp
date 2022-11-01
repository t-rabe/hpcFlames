#include "../headers/ApplyFuncs.hpp"

// initialize all of the data points by iterating through indices
ApplyFuncs::ApplyFuncs(vector<vector<int>> indices, vecFuncs a[], Funcs funcs) {
    this->indices = indices;
    for (unsigned int i=0; i<indices.size(); i++) {
        vector<vector<float>> intermed(indices[0].size(),vector<float>(2, 0.0));
        data.push_back(intermed);
    }
    this->assignSamples(indices, a, funcs);
}


void ApplyFuncs::iterateSample(vector<int> indSample, vecFuncs a[], Funcs funcs, int index) {
    vector<float> point = {0.1,0.1};
    vector<float> temp = point;
    for (unsigned int k=0; k<indSample.size(); k++) {
//        point = std::invoke(a[indSample[k]], funcs, temp);
	point = CALL_MEMBER_FN(funcs, a[indSample[k]]) (temp);
        data[index][k] = point;
        data[index][k].push_back(indSample[k]);
        temp = point;
    }
    
}


void ApplyFuncs::assignSamples(vector<vector<int>> indices, vecFuncs a[], Funcs funcs) {
    vector<thread> tasks;
    
    for (unsigned int j=0; j<indices.size(); j++) {
        int ind = (int) (j);
        tasks.push_back(thread(&ApplyFuncs::iterateSample, this, indices[ind], a, funcs, ind));
    }
    for (unsigned int f=0; f<tasks.size(); f++) {
        tasks[f].join();
    }
}


vector<vector<float>> ApplyFuncs::getData() {
    vector<vector<float>> tempData;
    for (unsigned int n=0; n<data.size(); n++) {
        for (unsigned int m=0; m<data[0].size(); m++) {
            tempData.push_back(data[n][m]);
        }
    }
    return tempData;
}

// returns data seperated into samples still
vector<vector<vector<float>>> ApplyFuncs::getData2() {
    return data;
}
