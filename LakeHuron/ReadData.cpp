//
//  ReadData.cpp
//  LakeHurton
//
//  Created by Dario Caric on 01.04.2024..
//

#include "ReadData.hpp"
#include <sstream>

ReadData::ReadData(string fileName){
    this->fileName = fileName;
    this->entries = vector<Data>(); // reset list
    
    // call function to read file and load data into entries variable
    readEntries();
}

ReadData::~ReadData() {
    cout << "ReadData object destroyed" << endl;
}

void ReadData::readEntries() {
    ifstream file = ifstream(fileName);
    string line;
    
    if (!file) {
        cout << "File not found" << endl;
    }

    // file is found, now parse file and find highes level
    // skip the header
    getline(file, line);
    
    //while (getline(file, line, ',')) {
    while (getline(file, line)) {

        Data tmp;
        
        // method 1
        string value;
        stringstream sstr(line);
        
        // Extract the id
        getline(sstr, value, ',');
        tmp.id = stoi(value);
        
        // Extract year
        getline(sstr, value, ',');
        tmp.year = stoi(value);

        // Extract level
        getline(sstr, value, '\n');
        tmp.level = stod(value);
        
        
        /*
        // method 2
        // exctract id
        stringstream sstr;
        sstr << line;
        sstr >> tmp.id;
        sstr.str("");
        sstr.clear();
        
        // exctract year
        getline(file, line, ',');
        sstr << line;
        sstr >> tmp.year;
        sstr.str("");
        sstr.clear();
        
        // excract level
        getline(file, line, '\n');
        sstr << line;
        sstr >> tmp.level;
        sstr.str("");
        sstr.clear();
        */
        
        //cout << tmp.year << " - " << tmp.level << endl;
        entries.push_back(tmp);
        
        
    }
}

Data ReadData::getHighestLevel() {
    
    Data highestlevel;
    double tempHighestLevel = entries[0].level; // set to the first value
    
    for (int i = 0; i < entries.size(); i++) {
        if (entries[i].level > tempHighestLevel) {
            tempHighestLevel = entries[i].level;
            highestlevel = entries[i];
        }
    }
    
    return highestlevel;
}
