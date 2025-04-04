#include <iostream>
#include <fstream>

#include "WordCount.h"

int WordCount::countWords(string filename) {
    ifstream file(filename);
    if(!file) {
        cout << "Error: Could not open file." << endl;
        return -1;
    }

    int count = 0;
    string word;
    while(file >> word) {
        ++count;
    }

    file.close();

    return count;
}