#include <iostream>
#include <fstream>

#include "LineCount.h"

int LineCount::countLines(string filename) {
    ifstream file(filename);
    if(!file) {
        cout << "Error: Could not open file." << endl;
        return -1;
    }

    string line;
    int count = 0;
    while(getline(file, line)) {
        ++count;
    }

    file.close();

    return count;
}