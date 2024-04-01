//
//  main.cpp
//  LakeHurton
//
//  Created by Dario Caric on 01.04.2024..
//

#include <iostream>
#include "ReadData.hpp"
#include <string>

using namespace std;

int main() {
    
    const string fileURL = "/Users/dariocaric/Working/c++/LakeHuron/LakeHuron/LakeHuron.csv";
    
    // create ReadData object
    ReadData data = ReadData(fileURL);
    
    // read highest level
    Data result = data.getHighestLevel();
    cout << "Highest level: " << result.level << " in year " << result.year << endl;
    
    //cout << "Highest level: " << highestLevel.level << " in year " << highestLevel.year << endl;

    return 0;
}
