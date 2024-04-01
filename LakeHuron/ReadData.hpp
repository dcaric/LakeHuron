//
//  ReadData.hpp
//  LakeHurton
//
//  Created by Dario Caric on 01.04.2024..
//

#ifndef ReadData_hpp
#define ReadData_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Data {
    int id;
    int year;
    double level;
};

class ReadData {
    
private:
    string fileName;
    vector<Data> entries;
    void readEntries();
    
public:
    ReadData(string fileName);
    ~ReadData();
    Data getHighestLevel();
    
    
};

#endif /* ReadData_hpp */
